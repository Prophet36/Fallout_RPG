// Character-derived class for human characters

#pragma once

#include <string>	// std::string
#include "Character.h"
#include "Item.h"
#include "Consumable.h"
#include "Armor.h"

class Human : public Character
{
public:
	Human();
	~Human();
	void showInventory() const;
	void addItemPrompt(std::string item_id);
protected:
	Item * inventory[10];
};

