#ifndef _HPP_ConsoleUtils_Write_
#define _HPP_ConsoleUtils_Write_

#include <windows.h>
#include <string>

namespace ConsoleUtils
{
    void Write      (const wchar_t*      text);
    void Write      (const char*         text);
    void Write      (const std::wstring& text);
    void Write      (const std::string&  text);
    void WriteLN    (const wchar_t*      text);
    void WriteLN    (const char*         text);
    void WriteLN    (const std::wstring& text);
    void WriteLN    (const std::string&  text);
    void WriteLN    ();
}

#endif // _HPP_ConsoleUtils_Write_
