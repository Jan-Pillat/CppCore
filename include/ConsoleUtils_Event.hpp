#ifndef _HPP_ConsoleUtils_Event_
#define _HPP_ConsoleUtils_Event_

#include <windows.h>

namespace ConsoleUtils
{
    INPUT_RECORD    GetEvent     ();
    void            GetEvent     (INPUT_RECORD* destination);
}

#endif // _HPP_ConsoleUtils_Event_
