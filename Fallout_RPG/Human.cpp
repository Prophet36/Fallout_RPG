#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Human.h"
#include "list_item_id.h"

Human::Human()
{
	inventory[0] = new Consumable(MEDKIT);
	inventory[1] = new Armor(LEATHER);
	inventory[2] = nullptr;
	inventory[3] = nullptr;
	inventory[4] = nullptr;
	inventory[5] = nullptr;
	inventory[6] = nullptr;
	inventory[7] = nullptr;
	inventory[8] = nullptr;
	inventory[9] = nullptr;
}

void Human::showInventory() const
{
	for (int i = 0; i < 10; i++)
	{
		if(inventory[i] != nullptr)
		inventory[i]->debug_print();
	}
}

void Human::addItem(std::string item_id)
{
	std::string buffer_s;

	std::fstream items ("item_id.txt");
	if(items.is_open())
	{
		bool item_found = false;

		while (getline(items, buffer_s))
		{
			if (buffer_s.find(item_id, 0) != std::string::npos)
			{
				std::cout << std::endl << buffer_s << std::endl << std::endl;
				item_found = true;
				break;
			}
		}
		if (!item_found)
		{
			std::cout << "ERROR: Incorrect item!\n";
		}
	}
	else
	{
		std::cout << "ERROR: Can't open file!\n";
	}
	items.close();
}

Human::~Human()
{
}
