// Item-derived class for consumable items

#pragma once

#include "Item.h"

enum attribute_type { STRENGTH, ENDURANCE, AGILITY, PERCEPTION, INTELLIGENCE,
					  LUCK, HEALTH, RADS };

class Consumable : public Item
{
public:
	Consumable(std::string name, std::string description, int attribute,
			   int magnitude, int duration, int value, double weight);
	~Consumable();

	virtual void debug_print() const override;
protected:
	int attribute;
	int magnitude;
	int duration;
};
