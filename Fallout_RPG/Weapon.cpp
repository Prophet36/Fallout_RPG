#include "stdafx.h"
#include "Weapon.h"
#include <iostream>	// std::cout

Weapon::Weapon(std::string name, std::string description, int damage,
               std::string roll, int speed, int penetration, int requirement,
               int value, double weight, std::string tags) :
    Item(name, description, value, weight, tags), m_damage(damage),
    m_roll(roll), m_speed(speed), m_penetration(penetration),
    m_requirement(requirement)
{
}

Weapon::~Weapon()
{
}
