#ifndef _CPP_ConsoleUtils_Event_
#define _CPP_ConsoleUtils_Event_

#include "../../include/ConsoleUtils/Event.hpp"

#ifndef _CPP_ConsoleUtils_consoleInputHandle
#define _CPP_ConsoleUtils_consoleInputHandle
    static HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleInputHandle

INPUT_RECORD ConsoleUtils::GetEvent ()
{
    DWORD   previousConsoleMode;
    GetConsoleMode(consoleInputHandle, &previousConsoleMode);
    SetConsoleMode(consoleInputHandle, ENABLE_PROCESSED_INPUT | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

    INPUT_RECORD    record = {0};

    while (true)
    {
        DWORD   readedRecors;
        if (ReadConsoleInput (consoleInputHandle, &record, 1, &readedRecors))
            break;
    }

    SetConsoleMode(consoleInputHandle, previousConsoleMode);

    return record;
}

void ConsoleUtils::GetEvent (INPUT_RECORD* destination)
{
    if (destination == nullptr)
        return;

    DWORD   previousConsoleMode;
    GetConsoleMode(consoleInputHandle, &previousConsoleMode);
    SetConsoleMode(consoleInputHandle, ENABLE_PROCESSED_INPUT | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

    while (true)
    {
        DWORD   readedRecors;
        if (ReadConsoleInput (consoleInputHandle, destination, 1, &readedRecors))
            break;
    }

    SetConsoleMode(consoleInputHandle, previousConsoleMode);
}

#endif // _CPP_ConsoleUtils_Event_
