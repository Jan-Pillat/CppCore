#ifndef _HPP_ConsoleUtils_Fill_
#define _HPP_ConsoleUtils_Fill_

#include <windows.h>

namespace ConsoleUtils
{
    void ColorfulFill   (const WORD colors);
    void ColorfulFill   (const ConsoleColor text, const ConsoleColor background);

    void CharFill       (const char ch);

    void Fill           (const char ch, const WORD colors);
    void Fill           (const char ch, const ConsoleColor text, const ConsoleColor background);

    void Clear          ();
    void Clear          (const char ch);
    void Clear          (const WORD colors);
    void Clear          (const ConsoleColor text, const ConsoleColor background);
}

#endif // _HPP_ConsoleUtils_Fill_
