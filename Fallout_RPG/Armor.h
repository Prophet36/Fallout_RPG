// Item-derived class for armor

#pragma once

#include "Item.h"
#include "list_armors.h"

class Armor : public Item
{
public:
	Armor(int type);
	~Armor();

	virtual void debug_print() const override;
protected:
	int reduction;
	int evasion;
	int protection;
};

