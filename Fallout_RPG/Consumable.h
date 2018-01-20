// Item-derived class for consumable items

#pragma once

#include "Item.h"
#include "list_consumables.h"

class Consumable : public Item
{
public:
	Consumable(int type);
	~Consumable();

	virtual void debug_print() const override;
protected:
	int attribute_type;
	int magnitude;
	int duration;
};
