// Character-derived class for human characters

#pragma once

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
protected:
	Item * inventory[10];
};

