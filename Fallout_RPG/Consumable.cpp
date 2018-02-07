#include "stdafx.h"
#include "Consumable.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Consumable::Consumable(std::string name, std::string description, int attribute,
                       int magnitude, int duration, int count, int value,
                       double weight, std::string tags) :
    Item(name, description, value, weight, tags), m_attribute(attribute),
    m_magnitude(magnitude), m_duration(duration), m_count(count)
{
}

Consumable::~Consumable()
{
}

void Consumable::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " Gives " << m_magnitude
              << " " << m_attribute << " for " << m_duration
              << " turns. You have " << m_count << " in this slot. VAL: "
              << m_value << " WG: " << m_weight << std::endl;
}

void Consumable::setCount(int count)
{
    m_count = count;
}

int Consumable::getCount() const
{
    return m_count;
}

std::string Consumable::getTags() const
{
    return m_tags;
}
