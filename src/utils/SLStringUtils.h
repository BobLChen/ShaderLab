#ifndef __SL_STRING_UTILS_H__
#define __SL_STRING_UTILS_H__

#include <string>
#include <vector>

namespace shaderlab
{
	using namespace std;

	inline bool IsDigit(char c) { return c >= '0' && c <= '9'; }
	inline bool IsAlpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
	inline bool IsSpace(char c) { return c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' '; }
	inline bool IsAlphaNumeric(char c) { return IsDigit (c) || IsAlpha (c); }
	inline bool IsNewline(char c) { return c == '\r' || c == '\n'; }

	inline char ToLower(char v)
	{
		if (v >= 'A' && v <= 'Z') { 
			return static_cast<char>(v | 0x20);
		} else {
			return v;
		}
	}

	inline char ToUpper(char v)
	{
		if (v >= 'a' && v <= 'z') {
			return static_cast<char>(v & 0xdf);
		} else {
			return v;
		}
	}

	template<typename StringType>
	StringType ToUpper(const StringType &input)
	{
		StringType ret = input;
		for (typename StringType::iterator it = ret.begin (); it != ret.end (); ++it) {
			*it = ToUpper(*it);
		}
		return ret;
	}

	template<typename StringType>
	StringType ToLower(const StringType &input)
	{
		StringType ret = input;
		for (typename StringType::iterator it = ret.begin (); it != ret.end (); ++it) {
			*it = ToLower(*it);
		}
		return ret;
	}

	template<typename ... Args>
	inline std::string FormatString(const std::string &format, Args ... args)
	{
		char buf[1024 * 6] = {0};
		size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
		snprintf(buf, size, format.c_str(), args ...);
		return std::string(buf, buf + size - 1);
	}

	size_t IndexOfToken(const string &text, const string &token, size_t startPos);
	size_t SkipWhiteSpace(const std::string &text, size_t startPos);
	size_t CountLines(const string &text, size_t endPos);
	size_t SkipToNextLine(const string &text, size_t startPos);
	std::string ReadNonWhiteSpace(const string &text, size_t &startPos);
	std::string ReadLine(const string &text, size_t startPos);
	void ExtractBlockString(string &input, string &output, const string &tokenStart, const string &tokenEnd);
	void ReplaceString(std::string &target, const string &search, const string &replace, size_t startPos = 0);
}

#endif