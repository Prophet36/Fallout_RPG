#include "stdafx.h"
#include "Item.h"
#include <iostream>
#include <string>

Item::Item(std::string name, std::string description, int value, double weight,
           std::string tags) :
    m_name(name), m_description(description), m_value(value),
    m_weight(weight), m_tags(tags)
{
    std::cout << "DEBUG: ----- Item " << m_name << " created! -----\n";
}

Item::~Item()
{
    std::cout << "DEBUG: ----- Item " << m_name << " destroyed! -----\n";
}
