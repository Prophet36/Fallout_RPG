#include "stdafx.h"
#include "Input.h"
#include <iostream>
#include <string>

void Input::keyContinue(bool prompt)
{
    if (prompt == true)
        std::cout << "\nPress ENTER to continue...";
    std::cin.get();
}

bool Input::yesNoPrompt()
{
    char choice;
    while (!(std::cin >> choice) ||
           choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        clearBuffer();
        std::cout << "Enter correct answer (y/n): ";
    }
    clearBuffer();
    tolower(choice);

    if (choice == 'y')
        return true;
    else
        return false;
}

char Input::getChar()
{
    char temp;
    while (!(std::cin >> temp))
    {
        clearBuffer();
        std::cout << "Enter correct character: ";
    }
    clearBuffer();
    return temp;
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

int Input::getPosInt()
{   
    int temp;
    while (!(std::cin >> temp) || temp < 1)
    {
        clearBuffer();
        std::cout << "Enter correct positive integer value: ";
    }
    clearBuffer();
    return temp;
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

void Input::clearBuffer()
{
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}
