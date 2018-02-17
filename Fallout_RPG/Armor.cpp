#include "stdafx.h"
#include "Armor.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Armor::Armor(std::string name, std::string description, int reduction,
             int evasion, int protection, int value, double weight,
             std::string tags) :
    Item(name, description, value, weight, tags), m_reduction(reduction),
    m_evasion(evasion), m_protection(protection)
{
}

Armor::~Armor()
{
}

void Armor::debugPrint() const
{
    std::cout << m_name << ": " << m_description << "\nDT: " << m_reduction << " EV: "
              << m_evasion << " PROT: " << m_protection << " VAL: " << m_value
              << " WG: " << m_weight << "\nTAGS: " << m_tags << std::endl;
}

std::string Armor::getTags() const
{
    return m_tags;
}
