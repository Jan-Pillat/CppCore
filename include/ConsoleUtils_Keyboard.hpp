#ifndef _HPP_ConsoleUtils_Keyboard_
#define _HPP_ConsoleUtils_Keyboard_

#include <windows.h>

namespace ConsoleUtils
{
    WORD  GetScanCode    ();
    WORD  GetKeyCode     ();
    WCHAR GetWchar       ();
    CHAR  GetChar        ();
}

#endif // _HPP_ConsoleUtils_Keyboard_
