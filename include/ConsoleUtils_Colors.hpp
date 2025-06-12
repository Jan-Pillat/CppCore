#ifndef _HPP_ConsoleUtils_Colors_
#define _HPP_ConsoleUtils_Colors_

#include <windows.h>

namespace ConsoleUtils
{
    enum ConsoleColor : WORD
    {
        INTENSITY    = FOREGROUND_INTENSITY,

        BLACK        = 0,
        RED          = FOREGROUND_RED,
        GREEN        = FOREGROUND_GREEN,
        BLUE         = FOREGROUND_BLUE,
        GRAY         = RED | GREEN | BLUE,
        CYAN         = BLUE  | GREEN,
        MAGENTA      = BLUE  | RED,
        YELLOW       = GREEN | RED,
        WHITE        = RED   | GREEN | BLUE,

        LIGHT_BLACK  = 0 | INTENSITY,
        LIGHT_RED    = FOREGROUND_RED     | INTENSITY,
        LIGHT_GREEN  = FOREGROUND_GREEN   | INTENSITY,
        LIGHT_BLUE   = FOREGROUND_BLUE    | INTENSITY,
        LIGHT_GRAY   = RED | GREEN | BLUE | INTENSITY,
        LIGHT_CYAN   = BLUE  | GREEN    | INTENSITY,
        LIGHT_MAGENTA= BLUE  | RED      | INTENSITY,
        LIGHT_YELLOW = GREEN | RED      | INTENSITY,
        LIGHT_WHITE  = RED   | GREEN | BLUE | INTENSITY,

        //aliases
        DARK_RED     = RED,
        DARK_GREEN   = GREEN,
        DARK_BLUE    = BLUE,
        DARK_GRAY    = GRAY,
        DARK_CYAN    = CYAN,
        DARK_MAGENTA = MAGENTA,
        DARK_YELLOW  = YELLOW,
        DARK_WHITE   = WHITE,
    };

    void SetColors (const WORD colors);
    void SetColors (const ConsoleColor text, const ConsoleColor background);
}

#endif // _HPP_ConsoleUtils_Colors_
