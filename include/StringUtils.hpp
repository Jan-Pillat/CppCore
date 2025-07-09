#ifndef _HPP_str_
#define _HPP_str_

#include <cctype>
#include <cstddef>
#include <string>
#include <windows.h>


    #define     IsHexNum(char)              isxdigit(char)
    #define     IsDecNum(char)              isdigit(char)
    #define     IsNum(char)                 isdigit(char)
    #define     IsAlOrNum(char)             isalnum(char)

    #define     IsHexDigit(char)            isxdigit(char)
    #define     IsDecDigit(char)            isdigit(char)
    #define     IsHexadecimalDigit(char)    isxdigit(char)
    #define     IsDecimalDigit(char)        isdigit(char)
    #define     IsDigit(char)               isdigit(char)
    #define     IsAlOrDigit(char)           isalnum(char)
    #define     IsAlOrDig(char)             isalnum(char)
    #define     IsDigitOrAl(char)           isalnum(char)
    #define     IsDigOrAl(char)             isalnum(char)
    #define     IsAlphaOrDigit(char)        isalnum(char)
    #define     IsAlphabeticOrDigit(char)   isalnum(char)
    #define     IsDigitOrAlpha(char)        isalnum(char)
    #define     IsDigitOrAlphabetic(char)   isalnum(char)

    #define     IsBlank(char)               isblank(char)
    #define     IsPunctator(char)           ispunct(char)
    #define     IsPunct(char)               ispunct(char)
    #define     IsAlpha(char)               isalpha(char)
    #define     IsAlphabetic(char)          isalpha(char)

    char*			GetFirstNullCharPointer     (const char* s);
    std::size_t		GetFirstNullCharIndex       (const char* s);
    std::wstring    ConvertCharTableToWstring   (const char* text);

#endif
