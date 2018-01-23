// Fallout_RPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Item.h"
#include "Consumable.h"
#include "Armor.h"
#include "Character.h"
#include "Human.h"
#include "Player.h"

int main()
{
	/*
	int type;
	Item * ptr = nullptr;

	do
	{
		std::cout << "DEBUG: What item to give? ";
		std::cin >> type;

		ptr = new Consumable(type);
		ptr->debug_print();
		delete ptr;

	} while (type >= 0);
	*/

	std::string id;

	Human * player = new Human;

	std::cin >> id;
	
	player->addItem(id);
	player->showInventory();

    return 0;
}
