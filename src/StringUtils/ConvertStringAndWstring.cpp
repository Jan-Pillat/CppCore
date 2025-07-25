#ifndef _CPP_StringUtils_ConvertStringAndWstring_
#define _CPP_StringUtils_ConvertStringAndWstring_

#include "../../include/StringUtils/ConvertStringAndWstring.hpp"

    std::wstring    ConvertCharTableToWstring   (const char* text)
    {
        //Get text size
        int size = MultiByteToWideChar(CP_ACP, 0, text, -1, nullptr, 0);
        //Prepare buffer
        std::wstring converted (size-1, L'\0');
        //Convert text and write it to the buffer
        MultiByteToWideChar (CP_ACP, 0, text, -1, &converted[0], size);
        //Return wstring
        return converted;
    }


    std::wstring    ConvertStringToWstring   (const char* text)
    {
        return ConvertCharTableToWstring(text);
    }


    std::wstring    ConvertStringToWstring   (const std::string& text)
    {
        return ConvertCharTableToWstring(text.c_str());
    }


    std::string    ConvertWcharTableToString   (const wchar_t* text)
    {
        //Get text size
        int size = WideCharToMultiByte(CP_UTF8, 0, text, -1, nullptr, 0, nullptr, nullptr);
        //Prepare buffer
        std::string converted (size-1, '\0');
        //Convert text and write it to the buffer
        WideCharToMultiByte (CP_UTF8, 0, text, -1, &converted[0], size, nullptr, nullptr);
        //Return wstring
        return converted;
    }


    std::string    ConvertWstringToString   (const wchar_t* text)
    {
        return ConvertWcharTableToString (text);
    }


    std::string    ConvertWstringToString   (const std::wstring& text)
    {
        return ConvertWcharTableToString (text.c_str());
    }

#endif
