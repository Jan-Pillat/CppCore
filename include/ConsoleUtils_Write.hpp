#ifndef _HPP_ConsoleUtils_Write_
#define _HPP_ConsoleUtils_Write_

#include <windows.h>
#include <string>


    //LN = Line End
    //ML = Multiline
    //US = Unsafe

namespace ConsoleUtils
{
    void WriteLN    ();

    //ONLY ONE LINE
    void Write      (const std::wstring& text);
    void Write      (const wchar_t*      text);
    void Write      (const wchar_t       ch  );
    void Write      (const wchar_t       ch, DWORD count);

    //LINE END
    void WriteLN    (const std::wstring& text);
    void WriteLN    (const wchar_t*      text);
    void WriteLN    (const wchar_t       ch  );
    void WriteLN    (const wchar_t       ch, DWORD count);

    //MULTILINE
    void WriteML    (const std::wstring& text);
    void WriteML    (const wchar_t*      text);
    void WriteML    (const wchar_t       ch  );
    void WriteML    (const wchar_t       ch, DWORD count);

    //MULTILINE + LINE END
    void WriteMLLN  (const std::wstring& text);
    void WriteMLLN  (const wchar_t*      text);
    void WriteMLLN  (const wchar_t       ch  );
    void WriteMLLN  (const wchar_t       ch, DWORD count);

    //UNSAFE + MULTILINE
    void USWriteML  (const std::wstring& text);
    void USWriteML  (const wchar_t*      text);
    void USWriteML  (const wchar_t       ch  );
    void USWriteML  (const wchar_t       ch, DWORD count);

    //UNSAFE + MULTILINE + LINE END
    void USWriteMLLN(const std::wstring& text);
    void USWriteMLLN(const wchar_t*      text);
    void USWriteMLLN(const wchar_t       ch  );
    void USWriteMLLN(const wchar_t       ch, DWORD count);

    // ----- ASNI -----

    //ONLY ONE LINE
    void Write      (const std::string&  text);
    void Write      (const char*         text);
    void Write      (const char          ch  );
    void Write      (const char          ch, DWORD count);

    //LINE END
    void WriteLN    (const std::string&  text);
    void WriteLN    (const char*         text);
    void WriteLN    (const char          ch  );
    void WriteLN    (const char          ch, DWORD count);

    //MULTILINE
    void WriteML    (const std::string&  text);
    void WriteML    (const char*         text);
    void WriteML    (const char          ch  );
    void WriteML    (const char          ch, DWORD count);

    //MULTILINE + LINE END
    void WriteMLLN  (const std::string&  text);
    void WriteMLLN  (const char*         text);
    void WriteMLLN  (const char          ch  );
    void WriteMLLN  (const char          ch, DWORD count);

    //UNSAFE + MULTILINE
    void USWriteML    (const std::string&  text);
    void USWriteML    (const char*         text);
    void USWriteML    (const char          ch  );
    void USWriteML    (const char          ch, DWORD count);

    //UNSAFE + MULTILINE + LINE END
    void USWriteMLLN  (const std::string&  text);
    void USWriteMLLN  (const char*         text);
    void USWriteMLLN  (const char          ch  );
    void USWriteMLLN  (const char          ch, DWORD count);

}

#endif // _HPP_ConsoleUtils_Write_
