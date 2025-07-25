#ifndef _CPP_ConvertNumberToHexString_
#define _CPP_ConvertNumberToHexString_


#include "../../include/StringUtils/ConvertNumberToHexString.hpp"

static const char BinNumToChar[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

std::string ConvertNumberToHexStringH (const long long number)
{
    char hexNumStr []
    {
        '0',
        BinNumToChar[(number&0xF000000000000000)>>60],
        BinNumToChar[(number&0x0F00000000000000)>>56],
        BinNumToChar[(number&0x00F0000000000000)>>52],
        BinNumToChar[(number&0x000F000000000000)>>48],
        BinNumToChar[(number&0x0000F00000000000)>>44],
        BinNumToChar[(number&0x00000F0000000000)>>40],
        BinNumToChar[(number&0x000000F000000000)>>36],
        BinNumToChar[(number&0x0000000F00000000)>>32],
        BinNumToChar[(number&0x00000000F0000000)>>28],
        BinNumToChar[(number&0x000000000F000000)>>24],
        BinNumToChar[(number&0x0000000000F00000)>>20],
        BinNumToChar[(number&0x00000000000F0000)>>16],
        BinNumToChar[(number&0x000000000000F000)>>12],
        BinNumToChar[(number&0x0000000000000F00)>> 8],
        BinNumToChar[(number&0x00000000000000F0)>> 4],
        BinNumToChar[(number&0x000000000000000F)>> 0],
        'h',
        '\0'
    };


    char* i = hexNumStr + 1;                                //+1 it's skip of the first zero

    while (*i=='0')                                         //skip zero
        i++;

    if (IsAlphabetic(*i))                                   //letter must be preceded by a number
        i--;

    return i;
}

std::string ConvertNumberToHexString0x (const long long number)
{
    char hexNumStr []
    {
        '0',
        '0',
        BinNumToChar[(number&0xF000000000000000)>>60],
        BinNumToChar[(number&0x0F00000000000000)>>56],
        BinNumToChar[(number&0x00F0000000000000)>>52],
        BinNumToChar[(number&0x000F000000000000)>>48],
        BinNumToChar[(number&0x0000F00000000000)>>44],
        BinNumToChar[(number&0x00000F0000000000)>>40],
        BinNumToChar[(number&0x000000F000000000)>>36],
        BinNumToChar[(number&0x0000000F00000000)>>32],
        BinNumToChar[(number&0x00000000F0000000)>>28],
        BinNumToChar[(number&0x000000000F000000)>>24],
        BinNumToChar[(number&0x0000000000F00000)>>20],
        BinNumToChar[(number&0x00000000000F0000)>>16],
        BinNumToChar[(number&0x000000000000F000)>>12],
        BinNumToChar[(number&0x0000000000000F00)>> 8],
        BinNumToChar[(number&0x00000000000000F0)>> 4],
        BinNumToChar[(number&0x000000000000000F)>> 0],
        '\0'
    };


    char* i = hexNumStr + 2;                                //+1 it's skip of the first zero

    while (*i=='0')                                         //skip zero
        i++;

    *(i-1) = 'x';

    return i-2;
}

std::string ConvertNumberToHexString (const char* prefix, const long long number, const char* postfix)
{
    char hexNumStr []
    {
        '0',
        BinNumToChar[(number&0xF000000000000000)>>60],
        BinNumToChar[(number&0x0F00000000000000)>>56],
        BinNumToChar[(number&0x00F0000000000000)>>52],
        BinNumToChar[(number&0x000F000000000000)>>48],
        BinNumToChar[(number&0x0000F00000000000)>>44],
        BinNumToChar[(number&0x00000F0000000000)>>40],
        BinNumToChar[(number&0x000000F000000000)>>36],
        BinNumToChar[(number&0x0000000F00000000)>>32],
        BinNumToChar[(number&0x00000000F0000000)>>28],
        BinNumToChar[(number&0x000000000F000000)>>24],
        BinNumToChar[(number&0x0000000000F00000)>>20],
        BinNumToChar[(number&0x00000000000F0000)>>16],
        BinNumToChar[(number&0x000000000000F000)>>12],
        BinNumToChar[(number&0x0000000000000F00)>> 8],
        BinNumToChar[(number&0x00000000000000F0)>> 4],
        BinNumToChar[(number&0x000000000000000F)>> 0],
        '\0'
    };


    char* i = hexNumStr + 1;                                //+1 it's skip of the first zero

    while (*i=='0')                                         //skip zero
        i++;

    if (*prefix == '\0' && IsAlphabetic(*i))                //letter must be preceded by a number
        i--;


    string result;
    result  = prefix;
    result += i;
    result += postfix;
    return result;
}

/*
inline std::string ConvertNumberToHexString (const string& prefix, const long long number, const string& postfix)
{
    return ConvertNumberToHexString (&prefix[0], number, &postfix[0]);
}
*/

#endif
