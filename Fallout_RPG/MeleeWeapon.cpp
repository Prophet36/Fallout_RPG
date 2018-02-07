#include "stdafx.h"
#include "MeleeWeapon.h"
#include <iostream> // std::cout, std::endl

MeleeWeapon::MeleeWeapon(std::string name, std::string description, int damage,
                         std::string roll, int speed, int penetration,
                         int requirement, int value, double weight,
                         std::string tags) :
    Weapon(name, description, damage, roll, speed, penetration, requirement,
           value, weight, tags)
{
}

MeleeWeapon::~MeleeWeapon()
{
}

void MeleeWeapon::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " DMG: " << m_damage
              << " + " << m_roll << "\nSPD: " << m_speed << " PEN: "
              << m_penetration << " ST: " << m_requirement << " VAL: "
              << m_value << " WG: " << m_weight << "\nTAGS: " << m_tags
              << std::endl;
}

void MeleeWeapon::setCount(int count)
{
}

int MeleeWeapon::getCount() const
{
    return 1;
}

int MeleeWeapon::getStack() const
{
    return 1;
}

std::string MeleeWeapon::getTags() const
{
    return m_tags;
}
