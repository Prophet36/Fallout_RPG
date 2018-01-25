// Item-derived class for weapons

#pragma once

#include <string>	// std::string
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	~Weapon();

	virtual void debug_print() const = 0;
protected:
	std::string roll;
	std::string tags;
	int damage;
	int speed;
	int penetration;
	int requirement;
};
