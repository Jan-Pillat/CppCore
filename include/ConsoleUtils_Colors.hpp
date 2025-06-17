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
        CYAN         = BLUE  | GREEN,
        MAGENTA      = BLUE  | RED,
        YELLOW       = GREEN | RED,
        GRAY         = RED   | GREEN | BLUE,
		

        LIGHT_BLACK  = 0 | INTENSITY,
        LIGHT_RED    = FOREGROUND_RED   | INTENSITY,
        LIGHT_GREEN  = FOREGROUND_GREEN | INTENSITY,
        LIGHT_BLUE   = FOREGROUND_BLUE  | INTENSITY,
        LIGHT_CYAN   = BLUE  | GREEN    | INTENSITY,
        LIGHT_MAGENTA= BLUE  | RED      | INTENSITY,
        LIGHT_YELLOW = GREEN | RED      | INTENSITY,
        WHITE        = RED   | GREEN | BLUE | INTENSITY,
    };

    void SetColors (const WORD colors);
    void SetColors (const ConsoleColor text, const ConsoleColor background);
}

#endif // _HPP_ConsoleUtils_Colors_
