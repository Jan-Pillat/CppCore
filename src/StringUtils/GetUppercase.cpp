#ifndef _CPP_GetUppercase_
#define _CPP_GetUppercase_


#include "../../include/StringUtils/GetUppercase.hpp"


std::string GetUppercase (const std::string& s)
{
    return GetUppercase(&s[0]);
}


std::string GetUppercase (const char* s)
{
    std::string converted = s;
    std::transform (converted.begin(), converted.end(), converted.begin(), ::toupper);

    return converted;
}


#endif
