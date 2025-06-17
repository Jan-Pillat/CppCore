#ifndef _HPP_ConsoleUtils_Size_
#define _HPP_ConsoleUtils_Size_

#include <windows.h>

namespace ConsoleUtils
{
    WORD GetBufferSizeX     ();
    WORD GetBufferSizeY     ();

    WORD GetWindowSizeX     ();
    WORD GetWindowSizeY     ();
    void GetWindowSizeXY    (COORD* coordinations);
}

#endif // _HPP_ConsoleUtils_Size_
