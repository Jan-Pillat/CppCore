#ifndef _CPP_ConsoleUtils_Fill_
#define _CPP_ConsoleUtils_Fill_

#include "../include/ConsoleUtils_Fill.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

void ConsoleUtils::ColorfulFill (const WORD colors)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;

    FillConsoleOutputAttribute(consoleHandle, colors, consoleSize, { 0, 0 }, &written);
}

//---------------------------------------------------------------------------------

void ConsoleUtils::ColorfulFill (const ConsoleColor text, const ConsoleColor background)
{
    ColorfulFill ( (background<<4)|text );
}

//---------------------------------------------------------------------------------

void ConsoleUtils::CharFill (const char ch)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;

    FillConsoleOutputCharacter(consoleHandle, ch, consoleSize, { 0, 0 }, &written);
}

//---------------------------------------------------------------------------------

void ConsoleUtils::Fill (const char ch, const WORD colors)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;

    FillConsoleOutputAttribute(consoleHandle, colors, consoleSize, { 0, 0 }, &written);
    FillConsoleOutputCharacter(consoleHandle, ch,     consoleSize, { 0, 0 }, &written);
}

//---------------------------------------------------------------------------------

void ConsoleUtils::Fill (const char ch, const ConsoleColor text, const ConsoleColor background)
{
    Fill ( ch, (background<<4)|text );
}

//---------------------------------------------------------------------------------

void ConsoleUtils::Clear ()
{
    CharFill (' ');
    SetConsoleCursorPosition ( consoleHandle, { 0, 0 } );
}

void ConsoleUtils::Clear (const char ch)
{
    CharFill (ch);
    SetConsoleCursorPosition ( consoleHandle, { 0, 0 } );
}

void ConsoleUtils::Clear (const WORD colors)
{
    Fill ( ' ', colors );
    SetConsoleCursorPosition ( consoleHandle, { 0, 0 } );
}

void ConsoleUtils::Clear (const ConsoleColor text, const ConsoleColor background)
{
    Fill ( ' ', (background<<4)|text );
    SetConsoleCursorPosition ( consoleHandle, { 0, 0 } );
}

#endif // _CPP_ConsoleUtils_Fill_
