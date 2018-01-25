// Weapon-derived class for ranged weapons

#pragma once

#include <string>	// std::string
#include "Weapon.h"

class RangedWeapon : public Weapon
{
public:
	RangedWeapon(std::string name, std::string description, int ammo_type,
				 int capacity, int damage, std::string roll, int speed,
				 int accuracy, int penetration, int requirement, int value,
				 double weight, std::string tags);
	~RangedWeapon();

	virtual void debug_print() const override;
private:
	int capacity;
	int ammo_type;
	int accuracy;
};
