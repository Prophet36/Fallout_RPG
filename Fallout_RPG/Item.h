// Base item class

#pragma once

#include <string>	// std::string

class Item
{
public:
	Item();
	~Item();

	virtual void debug_print() const = 0;
protected:
	std::string name;
	std::string description;
	int value;
	double weight;
};
