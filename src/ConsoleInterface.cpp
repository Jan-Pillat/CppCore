
#include "../include/ConsoleInterface.hpp"

using namespace ConsoleUtils;

void ConsoleInterface::DrawRowInterface () const
{
    SetWritePosition (buttonMarginX, buttonMarginY);

    for (int i = 0;  i<options.size();  i++)
    {
        if (i == optionFocus)
        {
            SetColors(buttonFoucsColors);

            Write   (focusButtonLeft);
            Write   (options[i].name);
            Write   (focusButtonRight);
        }
        else
        {
            SetColors(buttonColors);

            Write   (buttonLeft);
            Write   (options[i].name);
            Write   (buttonRight);
        }

        SetColors(otherColors);

        if (i != options.size()-1)
        {
            Write   (L"  ");
        }
    }
}

void ConsoleInterface::DrawColumnInterface () const
{
    SetColors(buttonColors);    //In the most cases, the selected buttons will be drawn, so there is no need to set the colors multiple times.

    for (int i = 0;  i<options.size();  i++)
    {
        SetWritePosition (buttonMarginX, buttonMarginY + (1+interButtonMargin)*i);

        if (i == optionFocus)
        {
            SetColors(buttonFoucsColors);

            Write   (focusButtonLeft);
            Write   (options[i].name);
            Write   (focusButtonRight);

            SetColors(buttonColors);
        }
        else
        {
            Write   (buttonLeft);
            Write   (options[i].name);
            Write   (buttonRight);
        }
    }

    SetColors(otherColors);
}

void  ConsoleInterface::Start   ()
{
    if (style == ROW)
    {
        DrawRowInterface ();
    }
    else
    {
        DrawColumnInterface ();
    }
}

void  ConsoleInterface::SetButtonColors         (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonColors        = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

void  ConsoleInterface::SetButtonFoucsColors    (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonFoucsColors   = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

void  ConsoleInterface::SetDescriptionColors    (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    descriptionColors   = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

void  ConsoleInterface::SetOtherColors          (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    otherColors         = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}
