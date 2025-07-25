#ifndef _HPP_ConvertNumberToHexString_
#define _HPP_ConvertNumberToHexString_

#include <string>
#include "CheckChar.hpp"

using std::string;

string ConvertNumberToHexStringH  (const long long number);
string ConvertNumberToHexString0x (const long long number);
string ConvertNumberToHexString   (const char*   prefix, const long long number, const char*   postfix);
//string ConvertNumberToHexString   (const string& prefix, const long long number, const string& postfix);

#endif
