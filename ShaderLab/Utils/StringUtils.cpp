#include "StringUtils.h"

namespace shaderlab
{
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
}