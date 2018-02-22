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

int Weapon::getMinDamage() const
{
    if (m_roll[0] == 'd')
    {
        return m_damage + 1;
    }
    else
    {
        return m_damage + (m_roll[0] - '0');
    }
}

int Weapon::getMaxDamage() const
{
    std::string temp = m_roll;
    int mult = 1;

    if (m_roll[0] == 'd')
    {
        temp.erase(temp.begin(), temp.begin() + 1);
        return m_damage + std::stoi(temp);
    }
    else
    {
        mult = m_roll[0] - '0';
        temp.erase(temp.begin(), temp.begin() + 2);
        return m_damage + (mult * std::stoi(temp));
    }
}
