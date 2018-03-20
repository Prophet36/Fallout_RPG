#pragma once

#include <string>   // std::string

/**
 * This class is for input managament, clearing stream buffer and handling bad
 * input.
 *
 * The class can't be instantiated and all its methods are static in order to
 * be able to freely use those methods whenever input from user is needed.
 *
 * @author  Mateusz Warchol
 */
class Input
{
public:
    /**
     * Constructor is inaccessible.
     */
    Input() = delete;

    /**
     * Destructor is inaccessible.
     */
    ~Input() = delete;

    /**
     * Waits for the user to press enter to continue. It can print the prompt,
     * or omit printing, which is the default setting.
     *
     * @param prompt    prints the prompt if true, otherwise doesn't print
     *                  anything (default value)
     */
    static void keyContinue(bool prompt = false);

    /**
     * Provides the user with 'yes' or 'no' prompt and asks the user for answer
     * with single characters ('y' or 'n') until the input is correct.
     *
     * @return  true, if user answered 'y' or 'Y', false, when answered 'n' or
     *          'N'
     */
    static bool yesNoPrompt();

    /**
     * Waits for user to input single character. When the input is bad, prompts
     * the user to input correctly.
     *
     * @return  character the user inputs
     */
    static char getChar();

    /**
     * Waits for user to input integer value. When the input is bad, prompts
     * the user to input correctly.
     *
     * @return  integer value the user inputs
     */
    static int getInt();

    /**
     * Waits for user to input positive integer value. When the input is bad,
     * prompts the user to input correctly.
     *
     * @return  positive integer value the user inputs
     */
    static int getPosInt();

    /**
     * Provides a switch (or ranged) prompt, asking user to input integer from
     * particular range. When the input is bad, prompts the user to input
     * correctly.
     *
     * @param low   lowest value of requested input range
     * @param high  highest value of requested input range
     * @return      value from the range the user inputs
     */
    static int switchPrompt(int low, int high);

    /**
     * Waits for user to input single string. When the input is bad, prompts
     * the user to input correctly.
     *
     * @return  string the user inputs
     */
    static std::string getString();

private:
    /**
     * Clears stream buffer for further input.
     */
    static void clearBuffer();
};
