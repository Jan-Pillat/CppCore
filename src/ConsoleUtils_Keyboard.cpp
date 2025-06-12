#ifndef _CPP_ConsoleUtils_Keyboard_
#define _CPP_ConsoleUtils_Keyboard_

#include "../include/ConsoleUtils_Keyboard.hpp"

#ifndef _CPP_ConsoleUtils_consoleHandle
#define _CPP_ConsoleUtils_consoleHandle
    static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleHandle

static DWORD  previousConsoleMode;
static bool   setConsoleMode = false;

void ConsoleUtils::Keyboard_Init ()
{
    GetConsoleMode(consoleHandle, &previousConsoleMode);

    if (previousConsoleMode == ENABLE_PROCESSED_INPUT)
    {
        setConsoleMode = false;
    }
    else
    {
        SetConsoleMode(consoleHandle, ENABLE_PROCESSED_INPUT);
        setConsoleMode = true;
    }
}

void ConsoleUtils::Keyboard_Exit ()
{
    if (setConsoleMode)
        SetConsoleMode(consoleHandle, previousConsoleMode);
}

#endif
