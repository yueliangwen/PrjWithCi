
#pragma once

#include <wchar.h>
#include <string>
#include <boost/locale.hpp>

inline std::string ansi_utf8( std::string const &source, const std::string &characters = "GB18030" )
{
	return boost::locale::conv::between( source, "UTF-8", characters ).c_str();
}

// convert wide string for console output aka native encoding
// because mixing std::wcout and std::cout is broken on windows
inline std::string utf8_ansi( std::string const &source, const std::string &characters = "GB18030" )
{
	return boost::locale::conv::between( source, characters, "UTF-8" ).c_str();
}

// convert utf8 for console output aka native encoding
// for linux ,  it does nothing (linux console always use utf8)
// for windows, it convert to CP_ACP
inline std::string console_out_str(const std::string & in)
{
#ifdef _WIN32
	return utf8_ansi(in);
#else
	return in;
#endif
}

