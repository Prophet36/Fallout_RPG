#include "stdafx.h"
#include <iostream>
#include "Armor.h"

Armor::Armor(int type)
{
	if (type >= ARMOR_COUNT)
	{
		std::cout << "ERROR: Incorrect armor!\n";
	}
	else
	{
		name = armor[type].name;
		description = armor[type].description;
		reduction = armor[type].reduction;
		evasion = armor[type].evasion;
		protection = armor[type].protection;
		value = armor[type].value;
		weight = armor[type].weight;
	}
}

void Armor::debug_print() const
{
}

Armor::~Armor()
{
}
