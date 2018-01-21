#include "stdafx.h"
#include "Human.h"


Human::Human()
{
	inventory[0] = new Consumable(Consumable::MEDKIT);
	inventory[1] = new Armor(Armor::LEATHER);
	inventory[2] = new Item();
	inventory[3] = new Item();
	inventory[4] = new Item();
	inventory[5] = new Item();
	inventory[6] = new Item();
	inventory[7] = new Item();
	inventory[8] = new Item();
	inventory[9] = new Item();
}

void Human::showInventory() const
{
	for (int i = 0; i < 10; i++)
	{
		inventory[i]->debug_print();
	}
}


Human::~Human()
{
}
