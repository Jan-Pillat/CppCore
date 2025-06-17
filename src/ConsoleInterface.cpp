
#include "../include/ConsoleInterface.hpp"

using namespace ConsoleUtils;

//================================================== DRAWING

void ConsoleInterface::DrawInterface () const
{
    // --- FIND THE BIGGEST BUTTON SIDES ---
    WORD descriptionPosX = buttonMarginX + descriptionMargin;
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
    //CLEAR SCREEN
    SetColors   (otherColors);
    Clear       (otherColors);
    //USER DRAWING
    if (additionalDrawing != nullptr)
        additionalDrawing ();
    //MARGINS
    SetWritePosition    (buttonMarginX, buttonMarginY);
    //DRAW BUTTONS AND ITS DESCRIPTIONS
    WORD optionPosY = buttonMarginY;
    for (int i = 0;  i<options.size();  i++)
    {
        int focusState = (i == optionFocus) ?1 :0 ;

        if (buttonRowSpacing > 0)
            SetWritePosition    (buttonMarginX, optionPosY);

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

        if (buttonRowSpacing > 0)
            SetWritePosition    (descriptionPosX, optionPosY);
        else
            ShiftWritePosition  (descriptionMargin, 0);
        SetColors           (buttonDescriptionColors[focusState]);
        Write               (options[i].buttonDescription);
        ShiftWritePosition  (interButtonMargin, 0);
        optionPosY += buttonRowSpacing;
    }

    //PREVENT DESCRIPTION FROM OVERLAPPING BUTTONS, IT'S IMPORTANT FOR ROW TABLE
    if ( (optionPosY==buttonMarginY) && (options.size()>0) )
        optionPosY += 1;

    // --- DRAW OPTION DESCRIPTION ---
    //COUNT DESCRIPTIONS
    int optionDescriptionCount = 0;
    for (int i = 0;  i<options.size();  i++)
        if (!options[i].optionDescription.empty() && options[i].optionDescription != L"")
            optionDescriptionCount++;

    //DRAW DESCRIPTIONS
    int freeSpace      = GetWindowSizeY() - optionPosY;
    int allocatedSpace = freeSpace;
    if (allocatedSpace > optionDescriptionSize)
        allocatedSpace = optionDescriptionSize;

    if (optionDescriptionCount > 0)
    {
        if (allocatedSpace > 0)
        {
            SetWritePosition    (0, GetWindowSizeY()-allocatedSpace);
            //BORDER
            if ( (allocatedSpace > 1) && (optionDescriptionBorder != L'\0') )
            {
                SetColors           (optionDescriptionBorderColors);
                WriteLN             (optionDescriptionBorder, GetWindowSizeX());
                allocatedSpace      -= 1;
            }
            //DESCRIPTION
            SetColors           (optionDescriptionColors);
            Rectangle           (' ', optionDescriptionColors, 0, GetWindowSizeY()-allocatedSpace, GetWindowSizeX(), GetWindowSizeY());
            WriteML             (options[optionFocus].optionDescription);
        }
    }

    SetColors(otherColors);
}

//================================================== MENU MANAGER

void  ConsoleInterface::Start   ()
{
    SetPositionVisibility (UNVISIBLE);
    bool draw = true;

    // -- SAFEGUARD --
    if (optionFocus >= options.size())
        optionFocus = 0;

    // -- INTERFACE LOOP --
    while (true)
    {
        // ----- DRAW -----
        if (draw)
        {
            DrawInterface ();
            draw = false;
        }

        // ----- EVENT REACT -----
        INPUT_RECORD event;
        GetEvent (&event);

        // --- WINDOW RESIZE ---
        if (event.EventType == WINDOW_BUFFER_SIZE_EVENT)
        {
            draw = true;
        }
        // --- KEYBOARD ---
        else if (event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown)
        {
            auto keyCode = event.Event.KeyEvent.wVirtualKeyCode;

            if (keyCode == VK_RETURN)
            {
                break;
            }
            else if ( (keyCode == VK_UP) || (keyCode == VK_LEFT) )
            {
                FocusPreviousOption();
                draw = true;
            }
            else if ( (keyCode == VK_DOWN) || (keyCode == VK_RIGHT) )
            {
                FocusNextOption();
                draw = true;
            }
        }
    }

    // ----- FINISH -----
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
    buttonColors[0]                 = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetButtonFoucsColors                (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonColors[1]                 = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetButtonDescriptionColors          (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonDescriptionColors[0]      = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetButtonDescriptionFocusColors     (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    buttonDescriptionColors[1]      = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetOptionDescriptionColors          (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    optionDescriptionColors         = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetOptionDescriptionBorderColors    (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    optionDescriptionBorderColors   = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}

//------------------------------------------------------------------------------------------------------------

void  ConsoleInterface::SetOtherColors                      (ConsoleColor textColor, ConsoleColor backgroundColor)
{
    otherColors                     = static_cast<ConsoleColor>( (backgroundColor << 4) + textColor );
}
