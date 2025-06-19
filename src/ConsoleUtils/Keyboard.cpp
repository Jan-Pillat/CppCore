#ifndef _CPP_ConsoleUtils_Keyboard_
#define _CPP_ConsoleUtils_Keyboard_

#include "../../include/ConsoleUtils/Keyboard.hpp"

#ifndef _CPP_ConsoleUtils_consoleInputHandle
#define _CPP_ConsoleUtils_consoleInputHandle
    static HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
#endif // _CPP_ConsoleUtils_consoleInputHandle

static DWORD  previousConsoleMode;
static bool   setConsoleMode = false;

//====================================================================

inline void Keyboard_Init ()
{
    GetConsoleMode(consoleInputHandle, &previousConsoleMode);

    if (previousConsoleMode == ENABLE_PROCESSED_INPUT)
    {
        setConsoleMode = false;
    }
    else
    {
        SetConsoleMode(consoleInputHandle, ENABLE_PROCESSED_INPUT);
        setConsoleMode = true;
    }
}

//====================================================================

inline void Keyboard_Exit ()
{
    if (setConsoleMode)
        SetConsoleMode(consoleInputHandle, previousConsoleMode);
}

//====================================================================

enum WHICH_RESULT
{
    KeyCode,
    ScanCode,
    ASCII,
    UNICODE
};

inline WORD GetEventResult (WHICH_RESULT which) //GetKeyCodeOfKeyPress
{
    Keyboard_Init ();

    INPUT_RECORD    record;
    DWORD           eventsRead;

    while (true)
    {
        if (which == ASCII)
            ReadConsoleInputA (consoleInputHandle, &record, 1, &eventsRead); //This return ASCII and -W returns UNICODE
        else
            ReadConsoleInputW (consoleInputHandle, &record, 1, &eventsRead); //This return UNICODE and -A returns ASCII

        // --- Get result ---
        if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown)
        {
            Keyboard_Exit ();

            if (which == KeyCode)
                return record.Event.KeyEvent.wVirtualKeyCode;

            else if (which == ScanCode)
                return record.Event.KeyEvent.wVirtualScanCode;

            else if (which == ASCII)
                return record.Event.KeyEvent.uChar.AsciiChar;

            else if (which == UNICODE)
                return record.Event.KeyEvent.uChar.UnicodeChar;
        }
    }
}

//====================================================================

WORD ConsoleUtils::GetKeyCode () //GetKeyCodeOfKeyPress
{
    return GetEventResult (KeyCode);
}

//====================================================================

WORD ConsoleUtils::GetScanCode () //GetScanCodeOfKeyPress
{
    return GetEventResult (ScanCode);
}

//====================================================================

CHAR ConsoleUtils::GetChar () //GetCharOfKeyPress
{
    return GetEventResult (ASCII);
}

//====================================================================

WCHAR ConsoleUtils::GetWchar () //GetWcharOfKeyPress
{
    return GetEventResult (UNICODE);
}

#endif
