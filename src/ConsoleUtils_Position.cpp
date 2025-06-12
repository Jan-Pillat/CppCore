#ifndef _CPP_ConsoleUtils_Position_
#define _CPP_ConsoleUtils_Position_

#include "../include/ConsoleUtils_Position.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

void ConsoleUtils::SetWritePosition (const short x, const short y)
{
    SetConsoleCursorPosition (consoleHandle, { x, y } );
}

void ConsoleUtils::ShiftWritePosition (const short shiftX, const short shiftY)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        SetConsoleCursorPosition (consoleHandle, { csbi.dwCursorPosition.X+shiftX, csbi.dwCursorPosition.Y+shiftY } );
    }

}

#endif
