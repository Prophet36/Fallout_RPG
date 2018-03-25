#include "stdafx.h"
#include "Human.h"
#include "Inventory.h"
#include <iostream>

Human::Human(std::string name, int level, int strength, int agility,
             int vitality, int perception, int intelligence, int luck) :
    Character(name, level, strength, agility, vitality, perception,
              intelligence, luck)
{
    m_inventory = new Inventory();
}

void Human::print() const
{

    std::cout << m_name << ": (" << m_inventory->getWeapon()->getName() << ", "
              << m_inventory->getArmor()->getName() << ")\n";

}
