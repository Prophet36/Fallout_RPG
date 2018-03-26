#include "stdafx.h"
#include "CritterWeapon.h"
#include <iostream>

CritterWeapon::CritterWeapon(std::string name, std::string description,
                             int damage, std::string roll, int speed,
                             int accuracy, int penetration, int rads,
                             int poison_chance, int poison_damage,
                             int poison_duration, std::string tags) :
    Weapon(name, description, damage, roll, speed, penetration, 0, 0, 0.0,
           tags), m_accuracy(accuracy), m_rads(rads),
    m_poison_chance(poison_chance), m_poison_damage(poison_damage),
    m_poison_duration(poison_duration)
{
}

void CritterWeapon::debugPrint() const
{
    std::cout << m_name << ": " << m_description << "\nDMG: " << m_damage
              << " + " << m_roll << " SPD: " << m_speed << " ACC: "
              << m_accuracy << " PEN: " << m_penetration << "\nDeals "
              << m_rads << " rads and has " << m_poison_chance
              << "% to inflict poison (" << m_poison_damage << ") for "
              << m_poison_duration << " turns\nTAGS: " << m_tags << std::endl;
}
