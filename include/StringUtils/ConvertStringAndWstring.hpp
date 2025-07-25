#ifndef _HPP_StringUtils_ConvertStringAndWstring_
#define _HPP_StringUtils_ConvertStringAndWstring_

#include <cstddef>
#include <string>
#include <windows.h>


    std::wstring    ConvertCharTableToWstring   (const char*         text);
    std::wstring    ConvertStringToWstring      (const char*         text); //alias to ConvertCharTableToWstring
    std::wstring    ConvertStringToWstring      (const std::string&  text);
    std::string     ConvertWcharTableToString   (const wchar_t*      text);
    std::string     ConvertWstringToString      (const wchar_t*      text); //alias to ConvertWcharTableToString
    std::string     ConvertWstringToString      (const std::wstring& text);

#endif
