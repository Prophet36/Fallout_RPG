#include "stdafx.h"
#include "Consumable.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Consumable::Consumable(std::string name, std::string description, int attribute,
                       int magnitude, int duration, int count, int stack,
                       int value, double weight, std::string tags) :
    Item(name, description, value, weight, tags), IStackable(count, stack),
    m_attribute(attribute), m_magnitude(magnitude), m_duration(duration)
{
}

Consumable::~Consumable()
{
}

void Consumable::debugPrint() const
{
    std::cout << m_name << ": " << m_description << "\nGives " << m_magnitude
              << " " << m_attribute << " for " << m_duration
              << " turns. You have " << m_count << " / " << m_stack
              << " in this slot.\nVAL: " << m_value * m_count << " WG: "
              << m_weight * m_count << "\nTAGS: " << m_tags << std::endl;
}
