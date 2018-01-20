#include "stdafx.h"
#include <iostream>
#include "Consumable.h"


Consumable::Consumable(int type)
{
	if (type >= CONSUMABLE_COUNT)
	{
		std::cout << "ERROR: Incorrect consumable!\n";
	}
	else
	{
		name = consumable[type].name;
		description = consumable[type].description;
		attribute_type = consumable[type].attribute_type;
		magnitude = consumable[type].magnitude;
		duration = consumable[type].duration;
		value = consumable[type].value;
		weight = consumable[type].weight;
	}
}

void Consumable::debug_print() const
{
	std::cout << name << ": " << description << "\nGives " << magnitude << " " << attribute_type << " for " << duration << " turns.\n"
			  << "Weights " << weight << " with a value of " << value << ".\n";
}

Consumable::~Consumable()
{
}
