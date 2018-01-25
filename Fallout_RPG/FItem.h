// Factory for item class objects

#pragma once

#include "Item.h"
#include <string>	// std::string
#include <fstream>	// std::fstream

class FItem
{
public:
	static Item * createNewItem(std::fstream & items, int item_type);
private:
	static Item * createNewConsumable(std::fstream & items);
	static Item * createNewMeleeWeapon(std::fstream & items, std::string tags);
	static Item * createNewRangedWeapon(std::fstream & items, std::string tags);
	static Item * createNewArmor(std::fstream & items);

	FItem();
	~FItem();
};
