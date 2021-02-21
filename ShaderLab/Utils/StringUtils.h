#pragma once

#include <string>

#include "Common/Common.h"

namespace shaderlab
{
	inline bool IsDigit(char c)
	{
		return c >= '0' && c <= '9';
	}

	inline bool IsAlpha(char c)
	{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}

	inline bool IsSpace(char c)
	{
		return c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ';
	}

	inline bool IsAlphaNumeric(char c)
	{
		return IsDigit(c) || IsAlpha(c);
	}

	inline bool IsNewline(char c)
	{
		return c == '\r' || c == '\n';
	}

	int32 IndexOfToken(const char* source, int32 sourceLen, const char* token, int32 tokenLen, int32 startPos);

	int32 ReadLine(const char* text, int32 size, int32 startPos);

	std::string ReadNonWhiteSpace(const char* text, int32 end, int32& startPos);

	void ReplaceString(std::string& target, const std::string& search, const std::string& replace, int32 startPos = 0);

	void FixErrorLineNumber(std::string& source, const std::string& fileName, int32 startLine);
}