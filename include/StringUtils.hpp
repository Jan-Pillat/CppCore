#ifndef _HPP_str_
#define _HPP_str_

#include <cstddef>
#include <string>
#include <windows.h>

    char*			GetFirstNullCharPointer     (const char* s);
    std::size_t		GetFirstNullCharIndex       (const char* s);
    std::wstring    ConvertCharTableToWstring   (const char* text);

#endif
