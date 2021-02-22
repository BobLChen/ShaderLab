﻿#include "StringUtils.h"

namespace shaderlab
{
	static const std::string g_Base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	int32 IndexOfToken(const char* source, int32 sourceLen, const char* token, int32 tokenLen, int32 startPos)
	{
		enum State
		{
			kStateText,
			kStateLineComment,
			kStateLongComment
		};

		int depth = 0;
		State state = kStateText;

		for (int32 i = startPos; i < sourceLen; ++i)
		{
			char c = source[i];
			if (state == kStateText)
			{
				if (c == '/' && i + 1 < sourceLen)
				{
					if (source[i + 1] == '/')
					{
						i++;
						state = kStateLineComment;
						continue;
					}
					if (source[i + 1] == '*')
					{
						i++;
						depth = 1;
						state = kStateLongComment;
						continue;
					}
				}
				if (c == token[0] && i + tokenLen <= sourceLen)
				{
					bool matched = true;
					for (int32 ti = 0; ti < tokenLen; ++ti)
					{
						if (*(token + ti) != *(source + i + ti))
						{
							matched = false;
							break;
						}
					}
					if (matched)
					{
						return i;
					}
				}
			}
			else if (state == kStateLineComment)
			{
				if (c == '\n' || c == '\r')
				{
					state = kStateText;
				}
			}
			else {
				if (i + 1 < sourceLen && c == '*' && source[i + 1] == '/')
				{
					i++;
					depth--;
					if (depth == 0)
					{
						state = kStateText;
					}
				}
				if (i + 1 < sourceLen && c == '/' && source[i + 1] == '*')
				{
					i++;
					depth++;
				}
			}
		}

		return -1;
	}

	int32 ReadLine(const char* text, int32 size, int32 startPos)
	{
		int32 end = startPos;
		while (end < size && !IsNewline(text[end]))
		{
			end++;
		}
		return end;
	}

	std::string ReadNonWhiteSpace(const char* text, int32 end, int32& startPos)
	{
		std::string ret;
		ret.reserve(end);

		while (startPos < end && isspace(text[startPos]))
		{
			startPos++;
		}

		while (startPos < end && !isspace(text[startPos]))
		{
			ret += text[startPos];
			startPos++;
		}

		return ret;
	}

	void ReplaceString(std::string& target, const std::string& search, const std::string& replace, int32 startPos)
	{
		if (search.empty()) 
		{
			return;
		}

		int32 p = startPos;
		while ((p = target.find(search, p)) != std::string::npos) 
		{
			target.replace(p, search.size(), replace);
			p += replace.size();
		}
	}

	void FixErrorLineNumber(std::string& source, const std::string& fileName, int32 startLine)
	{
		int32 pos = 0;
		while ((pos = source.find(fileName, pos)) != std::string::npos)
		{
			int32 lineStart = source.find(':', pos + fileName.size());
			int32 lineEnd   = source.find(':', lineStart + 1);
			int32 lineNumer = std::stoi(source.substr(lineStart + 1, lineEnd - lineStart - 1)) + startLine - 2;
			source.replace(lineStart + 1, lineEnd - lineStart - 1, std::to_string(lineNumer));
			pos += fileName.size();
		}
	}

	void Base64Encode(const uint8* source, int32 size, std::string& encodeString)
	{
		int32 i = 0;
		int32 j = 0;

		uint8 charArray3[3];
		uint8 charArray4[4];

		while (size--)
		{
			charArray3[i++] = *(source++);

			if (i == 3) 
			{
				charArray4[0] = ((charArray3[0] & 0xfc) >> 2);
				charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
				charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
				charArray4[3] = ((charArray3[2] & 0x3f));

				for (i = 0; i < 4; ++i)
				{
					encodeString += g_Base64Chars[charArray4[i]];
				}

				i = 0;
			}
		}

		if (i)
		{
			for (j = i; j < 3; ++j)
			{
				charArray3[j] = '\0';
			}

			charArray4[0] = ((charArray3[0] & 0xfc) >> 2);
			charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
			charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
			charArray4[3] = ((charArray3[2] & 0x3f));

			for (j = 0; j < i + 1; ++j)
			{
				encodeString += g_Base64Chars[charArray4[j]];
			}

			while (i++ < 3)
			{
				encodeString += '=';
			}
		}
	}

	void Base64Decode(const std::string& source, std::string& decodeString)
	{
		int32 size = source.size();
		int32 i    = 0;
		int32 j    = 0;
		int32 idx  = 0;

		uint8 charArray3[3];
		uint8 charArray4[4];
		
		while (size-- && (source[idx] != '=') && IsBase64(source[idx]))
		{
			charArray4[i++] = source[idx]; idx++;

			if (i == 4) 
			{
				for (i = 0; i < 4; ++i)
				{
					charArray4[i] = g_Base64Chars.find(charArray4[i]);
				}

				charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
				charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
				charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

				for (i = 0; i < 3; ++i)
				{
					decodeString += charArray3[i];
				}

				i = 0;
			}
		}

		if (i) 
		{
			for (j = i; j < 4; ++j)
			{
				charArray4[j] = 0;
			}

			for (j = 0; j < 4; ++j)
			{
				charArray4[j] = g_Base64Chars.find(charArray4[j]);
			}

			charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
			charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
			charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

			for (j = 0; j < i - 1; ++j)
			{
				decodeString += charArray3[j];
			}
		}
	}
}