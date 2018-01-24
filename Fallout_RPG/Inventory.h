#pragma once

#include <string>	// std::string

enum item_type { CONSUMABLE = 1, WEAPON, AMMO, ARMOR };

class Inventory
{
public:
	static int checkItemPrefix(std::string item_id);
	static int checkConsumableBonus(std::string bonus);
private:
	Inventory();
	~Inventory();
};
