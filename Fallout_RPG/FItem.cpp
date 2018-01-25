#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FItem.h"
#include "Item.h"
#include "Consumable.h"
#include "RangedWeapon.h"
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
			return createNewConsumable(items);
			break;
		}
		case item_type::WEAPON:
		{
			std::string tags;

			items.get();
			std::getline(items, tags, '\t');
			switch (Inventory::checkWeaponType(tags))
			{
				case weapon_type::MELEE:
				{
					std::cout << "DEBUG: Creating melee weapon!\n";
					return createNewRangedWeapon(items, tags);
					break;
				}
				case weapon_type::RANGED:
				{
					return createNewRangedWeapon(items, tags);
					break;
				}
				default:
				{
					std::cout << "ERROR: Unexpected error, incorrect weapon type!\n";
					break;
				}
			}
			break;
		}
		case item_type::ARMOR:
		{
			return createNewArmor(items);
			break;
		}
		default:
		{
			std::cout << "ERROR: Unexpected error, incorrect item type!\n";
			break;
		}
	}
}

Item * FItem::createNewConsumable(std::fstream & items)
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

	return new Consumable(name, description,
						  Inventory::checkConsumableBonus(attribute),
						  magnitude, duration, value, weight);
}

Item * FItem::createNewRangedWeapon(std::fstream & items, std::string tags)
{
	std::string name;
	std::string description;
	std::string ammo_type;
	std::string roll;
	int capacity;
	int damage;
	int speed;
	int accuracy;
	int penetration;
	int requirement;
	int value;
	double weight;

	std::getline(items, name, '\t');
	std::getline(items, description, '\t');
	std::getline(items, ammo_type, '\t');
	items >> capacity >> damage;
	items.get();
	std::getline(items, roll, '\t');
	items >> speed >> accuracy >> penetration >> requirement
		  >> value >> weight;

	return new RangedWeapon(name, description, 5, capacity, damage, roll, speed, accuracy, penetration, requirement, value, weight, tags);
}

Item * FItem::createNewArmor(std::fstream & items)
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

	return new Armor(name, description, reduction, evasion, protection,
					 value, weight);
}

FItem::~FItem()
{
}
