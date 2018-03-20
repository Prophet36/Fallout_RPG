#include "stdafx.h"
#include "RangedWeapon.h"
#include <iostream>

RangedWeapon::RangedWeapon(std::string name, std::string description,
                           std::string ammo_type, std::string ammo,
                           int capacity, int damage, std::string roll,
                           int speed, int accuracy, int penetration,
                           int requirement, int value, double weight,
                           std::string tags) :
    Weapon(name, description, damage, roll, speed, penetration, requirement,
           value, weight, tags), m_ammo_type(ammo_type), m_ammo(ammo),
    m_capacity(capacity), m_accuracy(accuracy)
{
    m_current_ammo = 0;
}

void RangedWeapon::debugPrint() const
{
    std::cout << m_name << ": " << m_description << "\nHas " << m_current_ammo
              << " / " << m_capacity << " " << m_ammo << " rounds.\nDMG: "
              << m_damage << " + " << m_roll << " SPD: " << m_speed << " ACC: "
              << m_accuracy << " PEN: " << m_penetration << " ST: "
              << m_requirement << "\nVAL: " << m_value << " WG: " << m_weight
              << "\nTAGS: " << m_tags << std::endl;
}
