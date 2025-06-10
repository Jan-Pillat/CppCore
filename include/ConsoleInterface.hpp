#ifndef _HPP_ConsoleInterface_
#define _HPP_ConsoleInterface_

#include <windows.h>

class ConsoleInterface
{
public:

    struct option
    {
        std::wstring name;
        std::wstring description;
    };

    enum InterfaceStyle
    {
        COLUMN,
        ROW
    };

    enum ButtonFocusVisual
    {
        SWAP_COLORS,
        INVERT_LIGHT,
        SET_COLORS
    };

    enum ButtonVisual
    {
        ANGLE,
        SQUARE,
        ROUND
    };

    vector <option> options;

    InterfaceStyle      interfaceStyle;
    ButtonFocusVisual   buttonFocusVisual;

    wchar_t             buttonLeft  = '[';
    wchar_t             buttonRight = ']';

    WORD buttonColors;
    WORD buttonFoucsColors;
    WORD otherColors;


    void Start              ();

    template <typename NAME, typename DESC>
    void AddOption          (NAME name, DESC description);//Auto convert char to wchar_t

    template <typename LEFT, typename RIGHT>
    void SetButtonVisual    (LEFT left, RIGHT right);   //Set chars of left and right bracket with auto convert char to wchar_t

    void SetButtonVisual    (ButtonVisual visual);      //Set chars of left and right bracket using the enum

    void SetButtonColors    (DWORD textColor, DWORD backgroundColor);//More readable than the buttonColors

};

#endif
