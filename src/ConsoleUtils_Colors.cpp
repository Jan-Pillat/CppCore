#ifndef _CPP_ConsoleUtils_Colors_
#define _CPP_ConsoleUtils_Colors_

#include "../include/ConsoleUtils_Colors.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

void ConsoleUtils::SetColors (const WORD colors)
{
    static BYTE previousColors;

    if (previousColors != colors)
    {
        previousColors  = colors;
        SetConsoleTextAttribute (consoleHandle, colors);
    }
}

void ConsoleUtils::SetColors (const ConsoleColor text, const ConsoleColor background)
{
    static BYTE lastText, lastBackground;

    if (lastText != text || lastBackground != background)
    {
        lastText        = text;
        lastBackground  = background;

        SetConsoleTextAttribute (consoleHandle, (background<<4)+text);
    }
}

#endif // _CPP_ConsoleUtils_Colors_
