#include "stdafx.h"
#include <iostream>	// std::cout
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(std::string name, std::string description, int ammo_type, int capacity, int damage, std::string roll, int speed, int accuracy, int penetration, int requirement, int value, double weight, std::string tags)
{
	this->name = name;
	this->description = description;
	this->ammo_type = ammo_type;
	this->capacity = capacity;
	this->damage = damage;
	this->roll = roll;
	this->speed = speed;
	this->accuracy = accuracy;
	this->penetration = penetration;
	this->requirement = requirement;
	this->value = value;
	this->weight = weight;
	this->tags = tags;
}

RangedWeapon::~RangedWeapon()
{
}

void RangedWeapon::debug_print() const
{
	std::cout << name << ": " << description << " Has " << capacity
			  << " " << ammo_type << " rounds.\nDMG: " << damage
			  << " + " << roll << " SPD: " << speed << " ACC: "
			  << accuracy << " PEN: " << penetration << " ST: "
			  << requirement << " VAL: " << value << " WG: " << weight
			  << "\nTAGS: " << tags << std::endl;
}
