#include "stdafx.h"
#include <iostream>	// std::cout
#include <fstream>	// std::fstream
#include <string>	// std::string, std::getline
#include "FItem.h"
#include "Item.h"
#include "Consumable.h"
#include "RangedWeapon.h"
#include "MeleeWeapon.h"
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
					return createNewMeleeWeapon(items, tags);
					break;
				}
				case weapon_type::RANGED:
				{
					return createNewRangedWeapon(items, tags);
					break;
				}
				default:
				{
					std::cout << "ERROR: Unexpected error,"
								 "incorrect weapon type!\n";
					return new RangedWeapon("Dummy Gun", "DEBUG: Dummy weapon.",
											ammo_type::PISTOL_SMALL, 0, 0, "d4",
											0, 0, 0, 0, 0, 0.0, "dummy");
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
			return new Consumable("Dummy Item", "DEBUG: Dummy item.",
								  attribute_type::HEALTH, 0, 0, 0, 0.0);
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

Item * FItem::createNewMeleeWeapon(std::fstream & items, std::string tags)
{
	std::string name;
	std::string description;
	std::string roll;
	int damage;
	int speed;
	int penetration;
	int requirement;
	int value;
	double weight;

	std::getline(items, name, '\t');
	std::getline(items, description, '\t');
	items >> damage;
	items.get();
	std::getline(items, roll, '\t');
	items >> speed >> penetration >> requirement >> value >> weight;

	return new MeleeWeapon(name, description, damage, roll, speed, penetration,
						   requirement, value, weight, tags);
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

	return new RangedWeapon(name, description, 5, capacity, damage, roll, speed,
							accuracy, penetration, requirement, value, weight,
							tags);
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
