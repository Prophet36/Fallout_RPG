// Static class for input handling and utility

#pragma once

#include <string>   // std::string

class Input
{
public:
    static void clearBuffer();
    static void keyContinue(bool prompt = false);
    static char getChar();
    static char yesNoPrompt();
    static int getInt();
    static int getPosInt();
    static int switchPrompt(int low, int high);
    static std::string getString();

private:
    Input();
    ~Input();
};
