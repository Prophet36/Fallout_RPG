#include "stdafx.h"
#include "RangedWeapon.h"
#include <iostream>	// std::cout, std::endl

RangedWeapon::RangedWeapon(std::string name, std::string description,
                           int ammo_type, int capacity, int damage,
                           std::string roll, int speed, int accuracy,
                           int penetration, int requirement, int value,
                           double weight, std::string tags) :
    Weapon(name, description, damage, roll, speed, penetration, requirement,
           value, weight, tags), m_ammo_type(ammo_type), m_capacity(capacity),
    m_accuracy(accuracy)
{
}

RangedWeapon::~RangedWeapon()
{
}

void RangedWeapon::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " Has " << m_capacity << " "
              << m_ammo_type << " rounds.\nDMG: " << m_damage << " + " << m_roll
              << " SPD: " << m_speed << " ACC: " << m_accuracy << " PEN: "
              << m_penetration << " ST: " << m_requirement << " VAL: "
              << m_value << " WG: " << m_weight << "\nTAGS: " << m_tags
              << std::endl;
}
