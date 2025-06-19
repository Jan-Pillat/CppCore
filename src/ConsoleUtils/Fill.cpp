#ifndef _CPP_ConsoleUtils_Fill_
#define _CPP_ConsoleUtils_Fill_

#include "../../include/ConsoleUtils/Fill.hpp"

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

void ConsoleUtils::Rectangle (const char ch, const WORD colors, WORD beginX, WORD beginY, WORD endX, WORD endY)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);

    auto windowSizeX  = csbi.srWindow.Right  - csbi.srWindow.Left + 1;
    auto windowSizeY  = csbi.srWindow.Bottom - csbi.srWindow.Top  + 1;

    if (beginX > endX)  std::swap(beginX, endX);
    if (beginY > endY)  std::swap(beginY, endY);

    if (beginX > windowSizeX)
        return;
    if (endX   < 0)
        return;
    if (endX > windowSizeX)
        endX -= endX-windowSizeX;

    if (beginY > windowSizeY)
        return;
    if (endY   < 0)
        return;
    if (endY > windowSizeY)
        endY -= endX-windowSizeY;


    auto rectangleSizeX = endX-beginX;
    auto rectangleSizeY = endY-beginY;

    DWORD written;

    for (int i=0;  i<rectangleSizeY;  i++)
    {
        FillConsoleOutputAttribute(consoleHandle, colors, rectangleSizeX, { beginX, beginY+i }, &written);
        FillConsoleOutputCharacter(consoleHandle, ch,     rectangleSizeX, { beginX, beginY+i }, &written);
    }
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
