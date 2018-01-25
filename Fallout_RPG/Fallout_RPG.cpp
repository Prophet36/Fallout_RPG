// Fallout_RPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	// std::cout, std::cin
#include <string>	// std::string
#include "Item.h"
#include "Consumable.h"
#include "Armor.h"
#include "Character.h"
#include "Human.h"
#include "Player.h"

int main()
{
	// DEBUG:
	std::string id;

	Human * player = new Human;

	int choice = 1;

	while (choice == 1)
	{
		std::cout << "DEBUG: Type item id: ";

		std::cin >> id;
		std::cin.get();
		std::cin.clear();

		player->addItemPrompt(id);
		player->showInventory();

		std::cout << "DEBUG: Add another item? (1): ";
		std::cin >> choice;
		std::cin.get();
		std::cin.clear();
	}

    return 0;
}
