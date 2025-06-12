#include <iostream>
#include <windows.h>
#include "../include/ConsoleInterface.hpp"

using namespace std;

//---------------- TEST


int ConsoleInterface_LibraryTest ()
{
    ConsoleInterface consoleInterface;

    //consoleInterface.SetButtonColors        (ConsoleUtils::BLACK,  ConsoleUtils::YELLOW);
    //consoleInterface.SetButtonFoucsColors   (ConsoleUtils::YELLOW, ConsoleUtils::BLACK);
    consoleInterface.style = ConsoleInterface::ROW;

    consoleInterface.AddOption(  "ĄĘÓŹ", "nothing");
    consoleInterface.AddOption( L"ĄĘÓŹ", "nothing");
    consoleInterface.AddOption(  "ĄĘÓŹ", L"something");
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");
    system ("cls");

    consoleInterface.style = ConsoleInterface::COLUMN;
    consoleInterface.Start();

    ConsoleUtils::WriteLN();
    system ("pause");

    return 0;
}
