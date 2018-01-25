#pragma once

#include <string>	// std::string

enum item_type { CONSUMABLE = 1, WEAPON, AMMO, ARMOR };
enum weapon_type { MELEE, RANGED };
enum ammo_type { PISTOL_SMALL, PISTOL_LARGE, REVOLVER_SMALL, REVOLVER_LARGE, RIFLE_SMALL, RIFLE_LARGE, RIFLE_SNIPER, ENERGY };

class Inventory
{
public:
	static int checkItemPrefix(std::string item_id);
	static int checkConsumableBonus(std::string bonus);
	static int checkWeaponType(std::string tags);
	static int checkAmmoType(std::string ammo_type);
private:
	Inventory();
	~Inventory();
};
