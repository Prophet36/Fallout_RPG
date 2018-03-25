#pragma once

#include "Human.h"
#include <iostream>

/**
 * This class is for handling menus and program navigation.
 *
 * The class can't be instantiated and all its methods are static in order to
 * be able to freely use those methods whenever menu navigation is needed.
 *
 * @author  Mateusz Warchol
 */
class Menu
{
public:
    /**
     * Constructor is inaccessible.
     */
    Menu() = delete;

    /**
     * Destructor is inaccessible.
     */
    ~Menu() = delete;

    /**
     * Prints and handles main menu of the program, enabling options to create,
     * delete and access characters.
     */
    static void main_menu();

private:
    /**
     * Prints and handles character menu, enabling options to modify that
     * character's parameters, items, etc.
     *
     * @param character pointer to Human class object for the menu's options to
     *                  work upon
     */
    static void character_menu(Human * character);
};
