
#include "../include/ConsoleInterface.hpp"

using namespace ConsoleUtils;

//================================================== DRAWING

void ConsoleInterface::DrawRowInterface () const
{
    SetWritePosition (buttonMarginX, buttonMarginY);

    for (int i = 0;  i<options.size();  i++)
    {
        int focusState = (i == optionFocus) ?1 :0 ;

        SetColors           (buttonColors[focusState]);

        Write               (buttonLeft[focusState]);
        Write               (options[i].name);
        Write               (buttonRight[focusState]);

        ShiftWritePosition  (interButtonMargin, 0);
    }
}

//---------------------------------------------------

void ConsoleInterface::DrawColumnInterface () const
{
    WORD descriptionPosX = buttonMarginX + descriptionPadding;

    // --- FIND THE BIGGEST BUTTON SIDES ---
    // - LEFT -
    if (buttonLeft[0].length() > buttonLeft[1].length())
        descriptionPosX += buttonLeft[0].length();
    else
        descriptionPosX += buttonLeft[1].length();
    // - RIGHT -
    if (buttonRight[0].length() > buttonRight[1].length())
        descriptionPosX += buttonRight[0].length();
    else
        descriptionPosX += buttonRight[1].length();

    // --- FIND THE BIGGEST BUTTON NAME ---
    WORD max = 0;
    for (int i = 0;  i<options.size();  i++)
    {
        WORD length = options[i].name.length();
        if (length > max)
            max = length;
    }
    descriptionPosX += max;

    // --- DRAW INTERFACE ---
    for (int i = 0;  i<options.size();  i++)
    {
        int focusState = (i == optionFocus) ?1 :0 ;

        SetWritePosition    (buttonMarginX, buttonMarginY + (1+interButtonMargin)*i);
        SetColors           (buttonColors[focusState]);

        WORD padding      = 0;
        WORD leftPadding  = 0;
        WORD rightPadding = 0;

        if ( (equalButtonSize==true) && (options[i].name.length() < max) )
        {
            padding      = max - options[i].name.length();
            leftPadding  = padding/2;
            rightPadding = padding-leftPadding;
        }

        Write               (buttonLeft[focusState]);
        Write               (' ', leftPadding);
        Write               (options[i].name);
        Write               (' ', rightPadding);
        Write               (buttonRight[focusState]);

        SetWritePosition    (descriptionPosX, buttonMarginY + (1+interButtonMargin)*i);
        SetColors           (descriptionColors[focusState]);

        Write               (options[i].description);
    }

    SetColors(otherColors);
}

//================================================== MENU MANAGER

void  ConsoleInterface::Start   ()
{
    SetPositionVisibility (UNVISIBLE);

    while (true)
    {
        Clear (otherColors);

        if (style == ROW)
        {
            DrawRowInterface ();
        }
        else
        {
            DrawColumnInterface ();
        }

        WORD keyCode = GetKeyCode();

        if (keyCode == VK_RETURN)
        {
            break;
        }
        else if ( (keyCode == VK_UP) || (keyCode == VK_LEFT) )
        {
            FocusPreviousOption();
        }
        else if ( (keyCode == VK_DOWN) || (keyCode == VK_RIGHT) )
        {
            FocusNextOption();
        }
    }

    Clear (otherColors);
    SetPositionVisibility (VISIBLE);

    options[optionFocus].react();
}

//---------------------------------------------------

void  ConsoleInterface::FocusNextOption   ()
{
    optionFocus++;
    if (optionFocus>=options.size())
        optionFocus=0;
}

//---------------------------------------------------

void  ConsoleInterface::FocusPreviousOption   ()
{
    optionFocus--;
    if (optionFocus<0)
        optionFocus=options.size()-1;
}


//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetButtonColors             (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonColors[0]         = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetButtonFoucsColors        (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonColors[1]         = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetDescriptionColors        (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    descriptionColors[0]    = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetDescriptionFocusColors   (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    descriptionColors[1]    = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetOtherColors              (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    otherColors             = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}
