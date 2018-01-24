// Factory for item class objects

#pragma once

#include "Item.h"
#include <string>
#include <fstream>

class FItem
{
public:
	static Item * createNewItem(std::fstream & items, int item_type);
private:
	FItem();
	~FItem();
};

