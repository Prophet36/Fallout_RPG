#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Human.h"
#include "Inventory.h"
#include "FItem.h"

Human::Human()
{
	inventory[0] = nullptr;
	inventory[1] = nullptr;
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

void Human::addItemPrompt(std::string item_id)
{
	std::string buffer_s;
	bool item_found = false;

	std::fstream items ("item_id.txt");
	if(items.is_open())
	{

		if (int item_type = Inventory::checkItemPrefix(item_id))
		{
			while ((items >> buffer_s))
			{
				if (buffer_s == item_id)
				{
					item_found = true;
					inventory[0] = FItem::createNewItem(items, item_type);
					break;
				}
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
