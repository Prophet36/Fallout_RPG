#include "stdafx.h"
#include "Gameplay.h"
#include "Human.h"
#include "Input.h"
#include "Menu.h"
#include "Player.h"

void Menu::main_menu()
{
    Gameplay * game = Gameplay::start();

    int choice = 1;

    while (choice != 0)
    {
        std::cout << "What do you want to do? (0 - exit)\n"
                     "1 - new, "
                     "2 - del, "
                     "3 - print, "
                     "4 - modify, "
                     "5 - fight\n";
        choice = Input::switchPrompt(0, 5);
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter character's name: ";
                game->addCharacter();
                break;
            }
            case 2:
            {
                game->deleteCharacter();
                break;
            }
            case 3:
            {
                game->printCharacters();
                break;
            }
            case 4:
            {
                game->selectCharacter();
                if (Human * temp = dynamic_cast<Human *>(game->getCharacter()))
                {
                    character_menu(temp);
                }
                else
                {
                    std::cout << "You can't modify critters!";
                    Input::keyContinue();
                }
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
    game->stop();
}

void Menu::character_menu(Human * character)
{
    int choice = 1;

    while (choice != 0)
    {
        std::cout << "What do you want to do? (0 - exit)\n"
                     "1 - add, "
                     "2 - del, "
                     "3 - show, "
                     "4 - eq, "
                     "5 - uneq, "
                     "6 - rl, "
                     "7 - unl\n";
        choice = Input::switchPrompt(0, 7);
        switch (choice)
        {
            case 1:
            {
                if (character->getInventory()->warnEncumbrance())
                {
                    std::cout << "DEBUG: Type item id: ";
                    character->getInventory()->add(Input::getString());
                }
                break;
            }
            case 2:
            {
                character->getInventory()->remove();
                break;
            }
            case 3:
            {
                character->getInventory()->print(true);
                break;
            }
            case 4:
            {
                character->getInventory()->equip();
                break;
            }
            case 5:
            {
                character->getInventory()->unequip();
                break;
            }
            case 6:
            {
                character->getInventory()->reloadWeapon();
                break;
            }
            case 7:
            {
                character->getInventory()->unloadWeapon();
                break;
            }
            case 0:
            {
                std::cout << "Exiting...\n";
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
}