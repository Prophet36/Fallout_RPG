// Static class for input handling and utility

#pragma once

#include <string>   // std::string

class Input
{
public:
    static void clearBuffer();
    static int getInt();
    static std::string getString();
    static char yesNoPrompt();
    static int switchPrompt(int low, int high);
    static void keyContinue(bool prompt = true);

private:
    Input();
    ~Input();
};
