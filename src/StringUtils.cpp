#include "../include/StringUtils.hpp"

    char*			GetFirstNullCharPointer     (const char* s)
    {
        return strchr(s, '\0');;
    }


    std::size_t		GetFirstNullCharIndex       (const char* s)
    {
        return strlen(s);
    }


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
