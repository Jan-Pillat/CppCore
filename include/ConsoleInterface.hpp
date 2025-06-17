#ifndef _HPP_ConsoleInterface_
#define _HPP_ConsoleInterface_

#include <windows.h>
#include <vector>
#include <string>
#include "ConsoleUtils.hpp" //enum:ConsoleColor (RED,WHITE,etc.); void:SetColors; void:Write;
#include "StringUtils.hpp"  //wstring:ConvertCharTableToWstring

using namespace ConsoleUtils;

class ConsoleInterface
{
private:
    void DrawRowInterface    () const;
    void DrawInterface       () const;
    void FocusNextOption     ();
    void FocusPreviousOption ();
public:

    struct option
    {
        std::wstring name;
        std::wstring buttonDescription;
        std::wstring optionDescription;

        void (*react)();

        WORD positionX = -1;
        WORD positionY = -1;
    };

    std::vector <option> options;
    int optionFocus = 0;

    void            (*additionalDrawing)()      = nullptr;

    WORD            buttonMarginX               = 5;
    WORD            buttonMarginY               = 2;
    WORD            interButtonMargin           = 0;    //Space between buttons (only if buttonRowSpacing = 0)
    WORD            buttonRowSpacing            = 1;
    WORD            descriptionMargin           = 2;    //Space between button and its description
    WORD            optionDescriptionSize       = 4;

    wchar_t         optionDescriptionBorder     = L'-';

    std::wstring    buttonLeft[2]               = { L"[ ", L"< " };
    std::wstring    buttonRight[2]              = { L" ]", L" >" };

    bool            equalButtonSize             = true;


    //COLORS = (BACKGROUND<<4)|TEXT
    //index 0 = not focused; 1 = focus
    ConsoleColor    buttonColors[2]             = { WHITE, static_cast<ConsoleColor>(WHITE<<4) };
    ConsoleColor    buttonDescriptionColors[2]  = { WHITE, WHITE };
    ConsoleColor    optionDescriptionColors     =   WHITE;
    ConsoleColor    optionDescriptionBorderColors=  WHITE;
    ConsoleColor    otherColors                 =   WHITE;

    //Functions that are more readable than using the variables
    void SetButtonColors                    (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetButtonFoucsColors               (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetButtonDescriptionColors         (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetButtonDescriptionFocusColors    (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetOptionDescriptionColors         (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetOptionDescriptionBorderColors   (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetOtherColors                     (ConsoleColor textColor, ConsoleColor backgroundColor);

    void Start              ();
/*
    template <typename LEFT, typename RIGHT>
    void SetButtonVisual    (LEFT left, RIGHT right);   //Set chars of left and right bracket with auto convert char to wchar_t

    void SetButtonColors    (DWORD textColor, DWORD backgroundColor);
*/

    //--------------------------------------------------------- TEMPLATES
    template <typename NAME, typename BUTTON_DESC, typename OPTION_DESC>
    void AddOption          ( void (*pointer)(), NAME name, BUTTON_DESC buttonDescription, OPTION_DESC optionDescription) //Auto convert char to wchar_t
    {
        static_assert (std::is_same_v<std::decay_t<NAME>,        const char*> || std::is_same_v<std::decay_t<NAME>,        const wchar_t*> || std::is_same_v<std::decay_t<NAME>,        std::string> || std::is_same_v<std::decay_t<NAME>,        std::wstring>, "Name type is wrong! AddOption (react, name, description) accepts only char* or wchar_t* or string or wstring for name and descriptions");
        static_assert (std::is_same_v<std::decay_t<BUTTON_DESC>, const char*> || std::is_same_v<std::decay_t<BUTTON_DESC>, const wchar_t*> || std::is_same_v<std::decay_t<BUTTON_DESC>, std::string> || std::is_same_v<std::decay_t<BUTTON_DESC>, std::wstring>, "Button descitpion type is wrong! AddOption (react, name, buttonDescription, optionDescription) accepts only char* or wchar_t* or string or wstring for name and descriptions");
        static_assert (std::is_same_v<std::decay_t<OPTION_DESC>, const char*> || std::is_same_v<std::decay_t<OPTION_DESC>, const wchar_t*> || std::is_same_v<std::decay_t<OPTION_DESC>, std::string> || std::is_same_v<std::decay_t<OPTION_DESC>, std::wstring>, "Option descitpion type is wrong! AddOption (react, name, buttonDescription, optionDescription) accepts only char* or wchar_t* or string or wstring for name and descriptions");

        option newOption;

        // ----- SCRIPT -----
        if (pointer == nullptr)
            return;
        else
            newOption.react = pointer;

        // ----- NAME -----
        if constexpr (std::is_same_v<std::decay_t<NAME>, const wchar_t*>)
        {
            newOption.name = name;
        }
        else if constexpr (std::is_same_v<std::decay_t<NAME>, const char*>)
        {
            if (name != nullptr)
            {
                newOption.name = ConvertCharTableToWstring(name);
            }
            else
            {
                newOption.name = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<NAME>, std::string>)
        {
            if (!name.empty())
            {
                std::wstring conversion = ConvertCharTableToWstring(&name[0]);
                newOption.name = conversion;
            }
            else
            {
                newOption.name = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<NAME>, std::wstring>)
        {
            if (!name.empty())
            {
                newOption.name = name;
            }
            else
            {
                newOption.name = L"";
            }
        }


        // ----- BUTTON DESCRIPTION -----
        if constexpr (std::is_same_v<std::decay_t<BUTTON_DESC>, const wchar_t*>)
        {
            newOption.buttonDescription = buttonDescription;
        }
        else if constexpr (std::is_same_v<std::decay_t<BUTTON_DESC>, const char*>)
        {
            if (buttonDescription != nullptr)
            {
                newOption.buttonDescription = ConvertCharTableToWstring(buttonDescription);
            }
            else
            {
                newOption.buttonDescription = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<BUTTON_DESC>, std::string>)
        {
            if (!buttonDescription.empty())
            {
                std::wstring conversion = ConvertCharTableToWstring(&buttonDescription[0]);
                newOption.buttonDescription = conversion;
            }
            else
            {
                newOption.buttonDescription = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<BUTTON_DESC>, std::wstring>)
        {
            if (!buttonDescription.empty())
            {
                newOption.buttonDescription = buttonDescription;
            }
            else
            {
                newOption.buttonDescription = L"";
            }
        }


        // ----- OPTION DESCRIPTION -----
        if constexpr (std::is_same_v<std::decay_t<OPTION_DESC>, const wchar_t*>)
        {
            newOption.optionDescription = optionDescription;
        }
        else if constexpr (std::is_same_v<std::decay_t<OPTION_DESC>, const char*>)
        {
            if (optionDescription != nullptr)
            {
                newOption.optionDescription = ConvertCharTableToWstring(optionDescription);
            }
            else
            {
                newOption.optionDescription = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<OPTION_DESC>, std::string>)
        {
            if (!optionDescription.empty())
            {
                std::wstring conversion = ConvertCharTableToWstring(&optionDescription[0]);
                newOption.optionDescription = conversion;
            }
            else
            {
                newOption.optionDescription = L"";
            }
        }
        else if constexpr (std::is_same_v<std::decay_t<OPTION_DESC>, std::wstring>)
        {
            if (!optionDescription.empty())
            {
                newOption.optionDescription = optionDescription;
            }
            else
            {
                newOption.optionDescription = L"";
            }
        }


        // ----- FINISH -----
        options.push_back(newOption);
    }
    //--------------------------------------------------------- TEMPLATES END
};

#endif
