// Fallout_RPG.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Armor.h"
#include "Character.h"
#include "Consumable.h"
#include "Human.h"
#include "Input.h"
#include "Item.h"
#include "Player.h"
#include <iostream> // std::cout, std::cin
#include <string>   // std::string

int main()
{
    // DEBUG:
    std::string id;

    Human * player = new Human;

    int choice = 1;

    while (choice != 0)
    {
        std::cout << "DEBUG: Type item id: ";

        player->addItemPrompt(Input::getString());
        player->showInventory();

        std::cout << "DEBUG: What do you want to do now?\n"
                     "(1 - add item, 2 - remove item, 0 - exit): ";
        choice = Input::switchPrompt(0, 2);
        if (choice == 2)
            player->deleteItemPrompt();
    }

    return 0;
}
