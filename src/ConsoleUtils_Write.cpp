#ifndef _CPP_ConsoleUtils_Write_
#define _CPP_ConsoleUtils_Write_

#include "../include/ConsoleUtils_Write.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

// ---------- LINE END ----------

void ConsoleUtils::WriteLN ()
{
    USWrite (L"\r\n");
}

// ---------- UNICODE ----------

void ConsoleUtils::USWrite (const wchar_t* text)    //unsafe write
{
    DWORD written;
    auto  length = wcslen(text);

    WriteConsoleW(consoleHandle, text, length, &written, nullptr);
}

void ConsoleUtils::USWriteLN (const wchar_t* text)    //unsafe write + line end
{
    DWORD written;
    auto  length = wcslen(text);

    WriteConsoleW(consoleHandle, text, length, &written, nullptr);

    static const wchar_t lineEnd[3] = L"\r\n";
    WriteConsoleW(consoleHandle, &lineEnd, sizeof(lineEnd)-1, &written, nullptr);
}

void ConsoleUtils::Write (const wchar_t* text)
{
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;

    WORD  windowSizeX = info.srWindow.Right - info.srWindow.Left + 1;

    for (const wchar_t* p = text; *p!=L'\0'; p++)
    {
        if (info.dwCursorPosition.X >= windowSizeX)
            break;
        else
            info.dwCursorPosition.X++;

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
    Write   (text);
    WriteLN ();
}

void ConsoleUtils::Write (const std::wstring& text)
{
    Write (&text[0]);
}

void ConsoleUtils::WriteLN (const std::wstring& text)
{
    WriteLN (&text[0]);
}

void ConsoleUtils::Write (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    Write (&str[0]);
}

void ConsoleUtils::WriteLN (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    WriteLN (&str[0]);
}

void ConsoleUtils::Write (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        Write (ch);
}

void ConsoleUtils::WriteLN (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        Write (ch);
    WriteLN ();
}


// ---------- ANSI ----------

void ConsoleUtils::USWrite (const char* text) //unsafe write
{
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);
}

void ConsoleUtils::USWriteLN (const char* text) //unsafe write
{
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);

    static const char lineEnd[3] = "\r\n";
    WriteConsoleA(consoleHandle, &lineEnd, sizeof(lineEnd)-1, &written, nullptr);
}

void ConsoleUtils::Write (const char* text)
{

    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;

    WORD windowSizeX = info.srWindow.Right - info.srWindow.Left + 1;
    int freeSpace    = windowSizeX - info.dwCursorPosition.X;

    if (freeSpace > 0)
    {
        int length      = strlen(text);

        int count;
        if (freeSpace > length)
            count = length;
        else
            count = freeSpace;

        DWORD   written;
        WriteConsoleA(consoleHandle, text, count, &written, nullptr);
    }
}

void ConsoleUtils::WriteLN (const char* text)
{
    Write   (text);
    WriteLN ();
}

void ConsoleUtils::Write (const std::string& text)
{
    Write (&text[0]);
}

void ConsoleUtils::WriteLN (const std::string& text)
{
    WriteLN (&text[0]);
}

void ConsoleUtils::Write (const char ch)
{
    char str[2] = { ch, 0 };
    Write (&str[0]);
}

void ConsoleUtils::WriteLN (const char ch)
{
    char str[2] = { ch, 0 };
    WriteLN (&str[0]);
}

void ConsoleUtils::Write (const char ch, DWORD count)
{
    for (; count > 0; count--)
        Write (ch);
}

void ConsoleUtils::WriteLN (const char ch, DWORD count)
{
    for (; count > 0; count--)
        Write (ch);
    WriteLN ();
}

#endif
