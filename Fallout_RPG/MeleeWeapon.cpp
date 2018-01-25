#include "stdafx.h"
#include <iostream>	// std::cout
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(std::string name, std::string description, int damage,
						 std::string roll, int speed, int penetration,
						 int requirement,int value, double weight,
						 std::string tags)
{
	this->name = name;
	this->description = description;
	this->damage = damage;
	this->roll = roll;
	this->speed = speed;
	this->penetration = penetration;
	this->requirement = requirement;
	this->value = value;
	this->weight = weight;
	this->tags = tags;
}

MeleeWeapon::~MeleeWeapon()
{
}

void MeleeWeapon::debug_print() const
{
	std::cout << name << ": " << description << " DMG: " << damage << " + "
			  << roll << "\nSPD: " << speed << " PEN: " << penetration<< " ST: "
			  << requirement << " VAL: " << value << " WG: " << weight
			  << "\nTAGS: " << tags << std::endl;
}
