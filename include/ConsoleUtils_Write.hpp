#ifndef _HPP_ConsoleUtils_Write_
#define _HPP_ConsoleUtils_Write_

#include <windows.h>
#include <string>

    //LN = Line End
    //US = Unsafe

namespace ConsoleUtils
{
    void WriteLN    ();

    void Write      (const std::wstring& text);
    void Write      (const wchar_t*      text);
    void Write      (const wchar_t       ch  );
    void Write      (const wchar_t       ch, DWORD count);

    void Write      (const std::string&  text);
    void Write      (const char*         text);
    void Write      (const char          ch  );
    void Write      (const char          ch, DWORD count);

    void WriteLN    (const std::wstring& text);
    void WriteLN    (const wchar_t*      text);
    void WriteLN    (const wchar_t       ch  );
    void WriteLN    (const wchar_t       ch, DWORD count);

    void WriteLN    (const std::string&  text);
    void WriteLN    (const char*         text);
    void WriteLN    (const char          ch  );
    void WriteLN    (const char          ch, DWORD count);

    void USWrite    (const wchar_t*      text);
    void USWrite    (const char*         text);

    void USWriteLN  (const wchar_t*      text);
    void USWriteLN  (const char*         text);
}

#endif // _HPP_ConsoleUtils_Write_
