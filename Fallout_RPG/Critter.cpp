#include "stdafx.h"
#include "Critter.h"
#include <iostream>

Critter::Critter(std::string name, int level, int strength, int agility,
                 int vitality, int perception, int intelligence, int luck,
                 int health_bonus, std::string attack, int reduction,
                 int experience, std::string type) :
    Character(name, level, strength, agility, vitality, perception,
              intelligence, luck), m_health_bonus(health_bonus),
    m_reduction(reduction), m_experience(experience), m_type(type)
{
    m_inventory = new Inventory(attack);
}

void Critter::print() const
{
    std::cout << m_name << " (" << m_type << ", "
              << getInventory()->getWeapon()->getName() << ")\n";
}
