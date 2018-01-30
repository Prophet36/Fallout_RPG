#include "stdafx.h"
#include "Input.h"
#include <iostream> // std::cout, std::cin
#include <string>   // std::string

void Input::clearBuffer()
{
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}

int Input::getInt()
{
    int temp;
    while (!(std::cin >> temp))
    {
        clearBuffer();
        std::cout << "Enter correct integer value: ";
    }
    clearBuffer();
    return temp;
}

std::string Input::getString()
{
    std::string temp;
    while (!(std::cin >> temp))
    {
        clearBuffer();
        std::cout << "Enter correct string: ";
    }
    clearBuffer();
    return temp;
}

char Input::yesNoPrompt()
{
    char choice;
    while (!(std::cin >> choice) || choice != 'y' && choice != 'n')
    {
        clearBuffer();
        std::cout << "Enter correct value (y/n): ";
    }
    clearBuffer();

    return choice;
}

int Input::switchPrompt(int low, int high)
{
    int choice;
    while (!(std::cin >> choice) || choice < low || choice > high)
    {
        clearBuffer();
        std::cout << "Enter correct value (" << low << " - " << high << "): ";
    }
    clearBuffer();

    return choice;
}

void Input::keyContinue(bool prompt)
{
    if (prompt == true)
        std::cout << "\nPress ENTER to continue...";
    std::cin.get();
}

Input::Input()
{
}

Input::~Input()
{
}
