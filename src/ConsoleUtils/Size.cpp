#ifndef _CPP_ConsoleUtils_Size_
#define _CPP_ConsoleUtils_Size_

#include "../../include/ConsoleUtils/Size.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

WORD ConsoleUtils::GetBufferSizeX ()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        return csbi.dwSize.X;
    }
    else
    {
        return 0;
    }
}

//------------------------------------------------------------

WORD ConsoleUtils::GetBufferSizeY ()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        return csbi.dwSize.Y;
    }
    else
    {
        return 0;
    }
}


//============================================================

WORD ConsoleUtils::GetWindowSizeX ()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    else
    {
        return 0;
    }
}

//------------------------------------------------------------

WORD ConsoleUtils::GetWindowSizeY ()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    else
    {
        return 0;
    }
}

//------------------------------------------------------------

void ConsoleUtils::GetWindowSizeXY (COORD* coordinations)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi))
    {
        coordinations->X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        coordinations->Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    else
    {
        coordinations->X = 0;
        coordinations->Y = 0;
    }
}

#endif // _CPP_ConsoleUtils_Size_
