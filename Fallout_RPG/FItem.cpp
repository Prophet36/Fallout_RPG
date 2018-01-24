#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FItem.h"
#include "Item.h"
#include "Consumable.h"
#include "Armor.h"
#include "Inventory.h"

FItem::FItem()
{
}

Item * FItem::createNewItem(std::fstream & items, int item_type)
{
	switch (item_type)
	{
		case item_type::CONSUMABLE:
		{
			std::string name;
			std::string description;
			std::string attribute;
			int magnitude;
			int duration;
			int value;
			double weight;

			items.get();
			std::getline(items, name, '\t');
			std::getline(items, description, '\t');
			std::getline(items, attribute, '\t');
			items >> magnitude >> duration >> value >> weight;

			return new Consumable(name, description, Inventory::checkConsumableBonus(attribute), magnitude, duration, value, weight);
			break;
		}
		case item_type::ARMOR:
		{
			std::string name;
			std::string description;
			int reduction;
			int evasion;
			int protection;
			int value;
			double weight;

			items.get();
			std::getline(items, name, '\t');
			std::getline(items, description, '\t');
			items >> reduction >> evasion >> protection >> value >> weight;

			return new Armor(name, description, reduction, evasion, protection, value, weight);
			break;
		}
		default:
		{
			std::cout << "ERROR: Unexpected error, incorrect item type!\n";
			break;
		}
	}
}

FItem::~FItem()
{
}
