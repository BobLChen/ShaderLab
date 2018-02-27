#include "SLStringUtils.h"
#include <vector>

namespace shaderlab
{
	
	size_t IndexOfToken(const string &source, const string &token, size_t startPos)
	{
		enum State {
			kStateText,
			kStateLineComment,	// // comment
			kStateLongComment	// /* comment */
		};
		
		int depth = 0;
		State state = kStateText;
		size_t sourceLen = source.size();
		size_t tokenLen  = token.size();
		
		for (size_t i = startPos; i < sourceLen; ++i) {
			char c = source[i];
			if (state == kStateText) {
				if (c == '/' && i + 1 < sourceLen) {
					if (source[i + 1] == '/') {
						i++;
						state = kStateLineComment;
						continue;
					}
					if (source[i + 1] == '*') {
						i++;
						depth = 1;
						state = kStateLongComment;
						continue;
					}
				}
				if (c == token[0] && i + tokenLen <= sourceLen) {
					if (token == source.substr(i, tokenLen)) {
						return i;
					}
				}
			} else if (state == kStateLineComment) {
				if (c == '\n' || c == '\r') {
					state = kStateText;
				}
			} else {
				if (i + 1 < sourceLen && c == '*' && source[i + 1] == '/') {
					i++;
					depth--;
					if (depth == 0) {
						state = kStateText;
					}
				}
				if (i + 1 < sourceLen && c == '/' && source[i + 1] == '*') {
					i++;
					depth++;
				}
			}
		}
		return string::npos;
	}

	void ExtractBlockString(string &input, string &output, const string &tokenStart, const string &tokenEnd)
	{
		size_t begin = IndexOfToken(input, tokenStart, 0);
		while (begin != string::npos) {
			size_t end = IndexOfToken(input, tokenEnd, begin);
			if (end == string::npos) {
				return;
			}
			string codeString = input.substr(begin + tokenStart.size(), end - begin - tokenStart.size());
			input = input.erase(begin, end + tokenEnd.size() - begin);
			output += codeString;
			begin = IndexOfToken(input, tokenStart, begin);
		}
	}

	string ReadLine(const string &text, size_t startPos)
	{
		size_t size = text.size();
		size_t end  = startPos;
		while (end < size && !IsNewline(text[end])) {
			end++;
		}
		return text.substr(startPos, end - startPos);
	}
	
	size_t SkipWhiteSpace(const string &text, size_t startPos)
	{
		size_t end = text.size();
		while (startPos < end && isspace(text[startPos])) {
			startPos++;
		}
		return startPos;
	}
	
	string ReadNonWhiteSpace(const string &text, size_t &startPos)
	{
		string ret;
		size_t end = text.size();
		while (startPos < end && isspace(text[startPos])) {
			startPos++;
		}
		while (startPos < end && !isspace(text[startPos])) {
			ret += text[startPos];
			startPos++;
		}
		return ret;
	}

	size_t CountLines(const string &text, size_t endPos)
	{
		if (endPos >= text.size()) {
			endPos = text.size() - 1;
		}
		int lineCount = 0;
		for (size_t i = 0; i <= endPos; ++i) {
			char c = text[i];
			if (c == '\n') {
				lineCount++;
			} else if (c == '\r') {
				lineCount++;
				if (i < endPos && text[i + 1] == '\r') {
					lineCount++;
				}
				i++;
			}
		}
		return lineCount;
	}

	size_t SkipToNextLine(const string& text, size_t startPos)
	{
		size_t end = text.size();
		while (startPos < end && !IsNewline(text[startPos])) {
			startPos++;
		}
		while (startPos < end && IsNewline(text[startPos])) {
			startPos++;
		}
		return startPos;
	}
	
	void ReplaceString(string &target, const string &search, const string &replace, size_t startPos) {
		if (search.empty()) {
			return;
		}
		size_t p = startPos;
		while ((p = target.find (search, p)) != string::npos) {
			target.replace (p, search.size (), replace);
			p += replace.size ();
		}
	}
	
}