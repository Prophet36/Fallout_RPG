#include "stdafx.h"
#include "Consumable.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Consumable::Consumable(std::string name, std::string description, int attribute,
                       int magnitude, int duration, int value, double weight) :
    Item(name, description, value, weight), m_attribute(attribute),
    m_magnitude(magnitude), m_duration(duration)
{
}

void Consumable::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " Gives " << m_magnitude
              << " " << m_attribute << " for " << m_duration << " turns. VAL: "
              << m_value << " WG: " << m_weight << std::endl;
}

Consumable::~Consumable()
{
}
