#ifndef _HPP_ConsoleUtils_Position_
#define _HPP_ConsoleUtils_Position_

#include <windows.h>

namespace ConsoleUtils
{
    enum PositionVisibility
    {
        UNVISIBLE,
        VISIBLE
    };

    void SetWritePosition       (const short x,      const short y);
    void ShiftWritePosition     (const short shiftX, const short shiftY);
    void SetPositionVisibility  (PositionVisibility  visibility);
}

#endif // _HPP_ConsoleUtils_Keyboard_
