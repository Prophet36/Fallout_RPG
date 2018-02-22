#include "stdafx.h"
#include "Human.h"
#include "Input.h"
#include "Player.h"
#include <iostream> // std::cout, std::cin
#include <string>   // std::string

int main()
{
    Human * player = new Player;
    Human * enemy = new Player();

    int choice = 1;

    while (choice != 0)
    {

        std::cout << "DEBUG: What do you want to do?\n"
                     "(1 - add item, 2 - remove item, 3 - show inventory, 0 - exit): ";
        choice = Input::switchPrompt(0, 5);
        switch (choice)
        {
            case 1:
            {
                if(player->checkInventorySpace())
                {
                    std::cout << "DEBUG: Type item id: ";
                    player->addItemPrompt(Input::getString());
                }
                break;
            }
            case 2:
            {
                player->deleteItemPrompt();
                break;
            }
            case 3:
            {
                player->showInventory();
                break;
            }
            case 0:
            {
                std::cout << "Exiting...";
                Input::keyContinue();
                break;
            }
            default:
            {
                std::cout << "ERROR: Wrong answer!\n";
                break;
            }
        }
    }

    delete player;
    player = nullptr;

    Input::keyContinue(true);

    return 0;
}
