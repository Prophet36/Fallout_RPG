#include "stdafx.h"
#include "Human.h"
#include "Input.h"
#include "Player.h"
#include "File.h"
#include <iostream>
#include <string>
#include <vld.h>

int main()
{
    Human * player = new Player;

    int choice = 1;

    while (choice != 0)
    {
        std::cout << "DEBUG: What do you want to do?\n"
                     "1 - add, "
                     "2 - del, "
                     "3 - show, "
                     "4 - eq, "
                     "5 - uneq, "
                     "6 - rl, "
                     "7 - unl, "
                     "0 - exit: ";
        choice = Input::switchPrompt(0, 7);
        switch (choice)
        {
            case 1:
            {
                if(player->getInventory()->warnEncumbrance())
                {
                    std::cout << "DEBUG: Type item id: ";
                    player->getInventory()->add(Input::getString());
                }
                break;
            }
            case 2:
            {
                player->getInventory()->remove();
                break;
            }
            case 3:
            {
                player->getInventory()->print(true);
                break;
            }
            case 4:
            {
                player->getInventory()->equip();
                break;
            }
            case 5:
            {
                player->getInventory()->unequip();
                break;
            }
            case 6:
            {
                player->getInventory()->reloadWeapon();
                break;
            }
            case 7:
            {
                player->getInventory()->unloadWeapon();
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
