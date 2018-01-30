#include "stdafx.h"
#include "Armor.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Armor::Armor(std::string name, std::string description, int reduction,
             int evasion, int protection, int value, double weight) :
    Item(name, description, value, weight), m_reduction(reduction),
    m_evasion(evasion), m_protection(protection)
{
}

void Armor::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " DT: " << m_reduction << " EV: "
              << m_evasion << " PROT: " << m_protection << " VAL: " << m_value
              << " WG: " << m_weight << std::endl;
}

Armor::~Armor()
{
}
