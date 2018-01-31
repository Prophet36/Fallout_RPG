#include "stdafx.h"
#include "Ammo.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Ammo::Ammo(std::string name, std::string description, int stack,
           int current_count, int value, double weight) :
    Item(name, description, value, weight), m_stack(stack),
    m_current_count(current_count)
{
}

void Ammo::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " You have "
              << m_current_count << " / " << m_stack << " in this slot.\nVAL: "
              << m_value << " WG: " << m_weight << std::endl;
}

Ammo::~Ammo()
{
}
