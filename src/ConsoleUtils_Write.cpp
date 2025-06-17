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
    USWriteML (L"\r\n");
}


// ---------- UNICODE ----------

void ConsoleUtils::Write (const wchar_t* text)
{
    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;
    if (info.dwCursorPosition.Y < 0)
    {
        SetConsoleCursorPosition (consoleHandle, { 0, 0 } );
        return;
    }

    WORD  windowSizeX = info.srWindow.Right - info.srWindow.Left + 1;
    int freeSpace     = windowSizeX - info.dwCursorPosition.X;

    if (freeSpace > 0)
    {
        int length      = wcslen(text);

        int count;
        if (freeSpace > length)
            count = length;
        else
            count = freeSpace;

        DWORD   written = 0;
        bool    success = true;

        //If can't it write a char, it writes a placeholder
        while (count > 0)
        {
            success = WriteConsoleW(consoleHandle, text, count, &written, nullptr);
            if (success)
            {
                break;
            }
            else
            {
                count  -= written+1;
                text   += written+1;

                static const wchar_t fallback = L'?';
                WriteConsoleW(consoleHandle, &fallback, 1, &written, nullptr);
            }
        }//while
    }//if
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


// ---------- MULTILINE UNICODE ----------

void ConsoleUtils::WriteML (const wchar_t* text)
{
    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

        // IS POS Y CORRECT?
    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;
    if (info.dwCursorPosition.Y < 0)
    {
        SetConsoleCursorPosition (consoleHandle, { 0, 0 } );
        return;
    }

        // IS POS X CORRECT?
    WORD windowSizeX = info.srWindow.Right - info.srWindow.Left + 1;

    if (info.dwCursorPosition.X < 0)
        SetConsoleCursorPosition (consoleHandle, { 0, info.dwCursorPosition.Y } );
    else if (info.dwCursorPosition.X >= windowSizeX)
        SetConsoleCursorPosition (consoleHandle, { 0, info.dwCursorPosition.Y+=1 } );

        // LOOP VARIABLES
    int     count   = wcslen(text);
    DWORD   written = 0;
    bool    success = true;

    //If can't it write a char, it writes a placeholder
    while (count > 0)
    {
        success = WriteConsoleW(consoleHandle, text, count, &written, nullptr);
        if (success)
        {
            break;
        }
        else
        {
            count  -= written+1;
            text   += written+1;

            static const wchar_t fallback = L'?';
            WriteConsoleW(consoleHandle, &fallback, 1, &written, nullptr);
        }
    }
}

void ConsoleUtils::WriteMLLN (const wchar_t* text)
{
    WriteML (text);
    WriteLN ();
}

void ConsoleUtils::WriteML (const std::wstring& text)
{
    WriteML (&text[0]);
}

void ConsoleUtils::WriteMLLN (const std::wstring& text)
{
    WriteMLLN (&text[0]);
}

void ConsoleUtils::WriteML (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    WriteML (&str[0]);
}

void ConsoleUtils::WriteMLLN (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    WriteMLLN (&str[0]);
}

void ConsoleUtils::WriteML (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
}

void ConsoleUtils::WriteMLLN (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
    WriteLN ();
}


// ---------- UNSAFE MULTILINE UNICODE ----------

void ConsoleUtils::USWriteML (const wchar_t* text)    //unsafe write
{
    DWORD written;
    WriteConsoleW(consoleHandle, text, wcslen(text), &written, nullptr);
}

void ConsoleUtils::USWriteMLLN (const wchar_t* text)    //unsafe write + line end
{
    DWORD written;
    WriteConsoleW(consoleHandle, text, wcslen(text), &written, nullptr);

    static const wchar_t lineEnd[3] = L"\r\n";
    WriteConsoleW(consoleHandle, &lineEnd, sizeof(lineEnd)-1, &written, nullptr);
}

void ConsoleUtils::USWriteML (const std::wstring& text)
{
    USWriteML (&text[0]);
}

void ConsoleUtils::USWriteMLLN (const std::wstring& text)
{
    USWriteMLLN (&text[0]);
}

void ConsoleUtils::USWriteML (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    USWriteML (&str[0]);
}

void ConsoleUtils::USWriteMLLN (const wchar_t ch)
{
    wchar_t str[2] = { ch, 0 };
    USWriteMLLN (&str[0]);
}

void ConsoleUtils::USWriteML (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        USWriteML (ch);
}

void ConsoleUtils::USWriteMLLN (const wchar_t ch, DWORD count)
{
    for (; count > 0; count--)
        USWriteML (ch);
    WriteLN ();
}


// ---------- ANSI ----------


void ConsoleUtils::Write (const char* text)
{
    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;
    if (info.dwCursorPosition.Y < 0)
    {
        SetConsoleCursorPosition (consoleHandle, { 0, 0 } );
        return;
    }

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


// ---------- MULTILINE ANSI ----------

void ConsoleUtils::WriteML (const char* text)
{
    CONSOLE_SCREEN_BUFFER_INFO  info;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &info))
        return;

        // IS POS Y CORRECT?
    WORD windowSizeY = info.srWindow.Bottom - info.srWindow.Top + 1;

    if (info.dwCursorPosition.Y >= windowSizeY)
        return;
    if (info.dwCursorPosition.Y < 0)
    {
        SetConsoleCursorPosition (consoleHandle, { 0, 0 } );
        return;
    }

        // IS POS X CORRECT?
    WORD windowSizeX = info.srWindow.Right - info.srWindow.Left + 1;

    if (info.dwCursorPosition.X < 0)
        SetConsoleCursorPosition (consoleHandle, { 0, info.dwCursorPosition.Y } );
    else if (info.dwCursorPosition.X >= windowSizeX)
        SetConsoleCursorPosition (consoleHandle, { 0, info.dwCursorPosition.Y+=1 } );

        // WRITE
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);
}

void ConsoleUtils::WriteMLLN (const char* text)  //multiline, line end
{
    WriteML(text);
    WriteLN();
}

void ConsoleUtils::WriteML (const std::string& text)
{
    WriteML (&text[0]);
}

void ConsoleUtils::WriteMLLN (const std::string& text)
{
    WriteMLLN (&text[0]);
}

void ConsoleUtils::WriteML (const char ch)
{
    char str[2] = { ch, 0 };
    WriteML (&str[0]);
}

void ConsoleUtils::WriteMLLN (const char ch)
{
    char str[2] = { ch, 0 };
    WriteMLLN (&str[0]);
}

void ConsoleUtils::WriteML (const char ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
}

void ConsoleUtils::WriteMLLN (const char ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
    WriteLN ();
}


// ---------- UNSAFE MULTILINE ANSI ----------

void ConsoleUtils::USWriteML (const char* text)
{
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);
}

void ConsoleUtils::USWriteMLLN (const char* text)  //multiline, line end
{
    DWORD   written;
    WriteConsoleA(consoleHandle, text, strlen(text), &written, nullptr);

    static const char lineEnd[3] = "\r\n";
    WriteConsoleA(consoleHandle, &lineEnd, sizeof(lineEnd)-1, &written, nullptr);
}

void ConsoleUtils::USWriteML (const std::string& text)
{
    WriteML (&text[0]);
}

void ConsoleUtils::USWriteMLLN (const std::string& text)
{
    WriteMLLN (&text[0]);
}

void ConsoleUtils::USWriteML (const char ch)
{
    char str[2] = { ch, 0 };
    WriteML (&str[0]);
}

void ConsoleUtils::USWriteMLLN (const char ch)
{
    char str[2] = { ch, 0 };
    WriteMLLN (&str[0]);
}

void ConsoleUtils::USWriteML (const char ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
}

void ConsoleUtils::USWriteMLLN (const char ch, DWORD count)
{
    for (; count > 0; count--)
        WriteML (ch);
    WriteLN ();
}

#endif
