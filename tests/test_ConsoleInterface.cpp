#include <iostream>
#include <windows.h>
#include "../include/ConsoleInterface.hpp"

using namespace std;

//---------------- TEST
void opcja1 ()  { cout << "opcja1" << endl; }
void opcja2 ()  { cout << "opcja2" << endl; }
void opcja3 ()  { cout << "opcja3" << endl; }

int ConsoleInterface_LibraryTest ()
{
    ConsoleInterface consoleInterface;

    //consoleInterface.SetButtonColors        (ConsoleUtils::BLACK,  ConsoleUtils::YELLOW);
    //consoleInterface.SetButtonFoucsColors   (ConsoleUtils::YELLOW, ConsoleUtils::BLACK);
    consoleInterface.style = ConsoleInterface::ROW;

    consoleInterface.AddOption( opcja1,  "ĄĘÓŹ",  "1111111111111111");
    consoleInterface.AddOption( opcja2, L"ĄĘÓŹ",  "22222");
    consoleInterface.AddOption( opcja3,  "Ż",    L"33333333333333333333333333333");
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

    consoleInterface.style = ConsoleInterface::COLUMN;
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

    consoleInterface.SetDescriptionFocusColors(YELLOW, BLACK);
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

    return 0;
}
