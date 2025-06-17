#include <iostream>
#include <windows.h>
#include "../include/ConsoleInterface.hpp"

using namespace std;

//---------------- TEST
void opcja1 ()  { cout << "opcja1" << endl; }
void opcja2 ()  { cout << "opcja2" << endl; }
void opcja3 ()  { cout << "opcja3" << endl; }
void opcja4 ()  { cout << "opcja4" << endl; }

void additional ()  { cout << "--++--++--\n--++--++--\n--++--++--\n--++--++--" << endl; }

string  testString  =  "string";
wstring testWstring = L"wstring";

int ConsoleInterface_LibraryTest ()
{
    ConsoleInterface consoleInterface;

// ----- DEFAULT SETTINGS -----
    consoleInterface.AddOption( opcja1,  "ĄĘÓŹ",     "1111111111111111",    "A lot of 1");
    consoleInterface.AddOption( opcja2, L"ĄĘÓŹ",     "22222",               "A bit of 2");
    consoleInterface.AddOption( opcja3,  "Ż",       L"33333333333333333333333333333", "Too much!");
    consoleInterface.AddOption( opcja4,  testString, testWstring,           "different strings");
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

// ----- COLORS -----
    consoleInterface.additionalDrawing  =  additional;

    consoleInterface.SetButtonColors        (WHITE, GRAY);
    consoleInterface.SetButtonFoucsColors   (WHITE, BLACK);

    consoleInterface.SetButtonDescriptionColors         (LIGHT_YELLOW, BLACK);
    consoleInterface.SetButtonDescriptionFocusColors    (YELLOW, BLACK);

    consoleInterface.SetOptionDescriptionColors         (RED, BLACK);
    consoleInterface.SetOptionDescriptionBorderColors   (LIGHT_RED, BLACK);

    consoleInterface.SetOtherColors (BLACK, GREEN);

    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

// ----- optionDescription = empty => no description zone -----
    consoleInterface.additionalDrawing  =  nullptr;
    consoleInterface.options.clear();
    consoleInterface.AddOption( opcja1,  "opt1",     "desc1",    "");
    consoleInterface.AddOption( opcja2, L"opt2",    L"desc2",   L"");
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

// ----- ROW INTERFACE -----
    consoleInterface.additionalDrawing  =  nullptr;
    consoleInterface.interButtonMargin  =  2;
    consoleInterface.buttonRowSpacing   =  0;
    consoleInterface.options.clear();
    consoleInterface.AddOption( opcja1,  "opt1",     "desc1",    "");
    consoleInterface.AddOption( opcja2, L"opt2",    L"desc2",   L"");
    consoleInterface.AddOption( opcja3, L"opt3",    L"desc3",   L"3333333333333");
    consoleInterface.Start();

// ----- ROW INTERFACE WITHOUT BUTTON DESCRIPTIONS -----
    consoleInterface.additionalDrawing  =  nullptr;
    consoleInterface.interButtonMargin  =  2;
    consoleInterface.buttonRowSpacing   =  0;
    consoleInterface.options.clear();
    consoleInterface.AddOption( opcja1,  "opt1",     "",    "");
    consoleInterface.AddOption( opcja2, L"opt2",    L"",   L"");
    consoleInterface.AddOption( opcja3, L"opt3",    L"",   L"3333333333333");
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

    return 0;
}
