#ifndef _HPP_ConsoleInterface_
#define _HPP_ConsoleInterface_

#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include "ConsoleUtils.hpp" //enum:ConsoleColor (RED,WHITE,etc.); void:SetColors; void:Write;
#include "StringUtils.hpp"  //wstring:ConvertCharTableToWstring

using namespace ConsoleUtils;

class ConsoleInterface
{
private:
    void DrawRowInterface    () const;
    void DrawColumnInterface () const;
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
/*
    enum ButtonVisual
    {
        ANGLE,
        SQUARE,
        ROUND
    };
*/
    std::vector <option> options;
    int optionFocus = 0;

    InterfaceStyle  style = COLUMN;

    short           buttonMarginX = 5;
    short           buttonMarginY = 2;
    short           interButtonMargin = 0;

    std::wstring    buttonLeft       = L"[ ";
    std::wstring    buttonRight      = L" ]";
    std::wstring    focusButtonLeft  = L"< ";
    std::wstring    focusButtonRight = L" >";

    ConsoleColor  buttonColors       =   WHITE;
    ConsoleColor  buttonFoucsColors  =   WHITE;
    ConsoleColor  descriptionColors  =   WHITE;
    ConsoleColor  otherColors        =   WHITE;

    //Functions that are more readable than using the variables
    void SetButtonColors        (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetButtonFoucsColors   (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetDescriptionColors   (ConsoleColor textColor, ConsoleColor backgroundColor);
    void SetOtherColors         (ConsoleColor textColor, ConsoleColor backgroundColor);

    void Start              ();
/*
    template <typename LEFT, typename RIGHT>
    void SetButtonVisual    (LEFT left, RIGHT right);   //Set chars of left and right bracket with auto convert char to wchar_t

    void SetButtonVisual    (ButtonVisual visual);      //Set chars of left and right bracket using the enum

    void SetButtonColors    (DWORD textColor, DWORD backgroundColor);
*/

    //--------------------------------------------------------- TEMPLATES
    template <typename NAME, typename DESC>
    void AddOption          (NAME name, DESC description) //Auto convert char to wchar_t
    {
        static_assert (std::is_same_v<std::decay_t<NAME>, const char*> || std::is_same_v<std::decay_t<NAME>, const wchar_t*>, "Name type is wrong! AddOption (name, description) accepts only char* or wchar_t*");
        static_assert (std::is_same_v<std::decay_t<DESC>, const char*> || std::is_same_v<std::decay_t<DESC>, const wchar_t*>, "Descitpion type is wrong! AddOption (name, description) accepts only char* or wchar_t*");

        option newOption;

        // ----- NAME -----
        if constexpr (std::is_same_v<std::decay_t<NAME>, const char*>)
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
        else
        {
            newOption.name = name;
        }


        // ----- DESCRIPTION -----
        if constexpr (std::is_same_v<std::decay_t<DESC>, const char*>)
        {
            if (description != nullptr)
            {
                newOption.description = ConvertCharTableToWstring(description);
            }
            else
            {
                newOption.description = L"";
            }
        }
        else
        {
            newOption.description = description;
        }


        // ----- FINISH -----
        options.push_back(newOption);
    }
    //--------------------------------------------------------- TEMPLATES ENS
};

#endif
