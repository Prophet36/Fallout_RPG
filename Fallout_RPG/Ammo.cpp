#include "stdafx.h"
#include "Ammo.h"
#include <iostream>
#include <string>

Ammo::Ammo(std::string name, std::string description, int count, int stack,
           int value, double weight, std::string tags) :
    Item(name, description, value, weight, tags), IStackable(count, stack)
{
}

void Ammo::debugPrint() const
{
    std::cout << m_name << ": " << m_description << "\nYou have " << m_count
              << " / " << m_stack << " in this slot.\nVAL: "
              << m_value * m_count << " WG: " << m_weight * m_count
              << "\nTAGS: " << m_tags << std::endl;
}
