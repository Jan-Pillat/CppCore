#ifndef _CPP_StringUtils_GetFirstNullChar_
#define _CPP_StringUtils_GetFirstNullChar_

#include "../../include/StringUtils/GetFirstNullChar.hpp"

    char*			GetFirstNullCharPointer     (const char* s)
    {
        return strchr(s, '\0');;
    }


    std::size_t		GetFirstNullCharIndex       (const char* s)
    {
        return strlen(s);
    }

#endif
