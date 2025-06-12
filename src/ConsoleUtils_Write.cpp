#ifndef _CPP_ConsoleUtils_Write_
#define _CPP_ConsoleUtils_Write_

#include "../include/ConsoleUtils_Write.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

// ---------- UNICODE ----------

void ConsoleUtils::Write (const wchar_t* text)
{
    DWORD written;

    for (const wchar_t* p = text; *p!=L'\0'; p++)
    {
        //If can't it write a char, it writes a placeholder
        if (!WriteConsoleW(consoleHandle, p, 1, &written, nullptr))
        {
            wchar_t fallback = L'?';
            WriteConsoleW(consoleHandle, &fallback, 1, &written, nullptr);
        }
    }
}

void ConsoleUtils::WriteLN (const wchar_t* text)
{
    Write (text);
    Write (L"\r\n");
}

void ConsoleUtils::Write (const std::wstring& text)
{
    Write (&text[0]);
}

void ConsoleUtils::WriteLN (const std::wstring& text)
{
    WriteLN (&text[0]);
}


// ---------- ANSI ----------

void ConsoleUtils::Write (const char* text)
{
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);
}

void ConsoleUtils::WriteLN (const char* text)
{
    Write (text);
    Write ("\r\n");
}

void ConsoleUtils::Write (const std::string& text)
{
    Write (&text[0]);
}

void ConsoleUtils::WriteLN (const std::string& text)
{
    WriteLN (&text[0]);
}


// ---------- LINE END ----------

void ConsoleUtils::WriteLN ()
{
    Write (L"\r\n");
}

#endif
