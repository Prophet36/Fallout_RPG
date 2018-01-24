// Item-derived class for armor

#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor::Armor(std::string name, std::string description, int reduction, int evasion, int protection, int value, double weight);
	~Armor();

	virtual void debug_print() const override;
private:
	int reduction;
	int evasion;
	int protection;
};

