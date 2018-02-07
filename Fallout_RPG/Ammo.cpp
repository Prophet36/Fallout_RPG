#include "stdafx.h"
#include "Ammo.h"
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

Ammo::Ammo(std::string name, std::string description, int count, int stack,
           int value, double weight, std::string tags) :
    Item(name, description, value, weight, tags), m_count(count), m_stack(stack)
{
}

Ammo::~Ammo()
{
}

void Ammo::debugPrint() const
{
    std::cout << m_name << ": " << m_description << " You have " << m_count
              << " / " << m_stack << " in this slot.\nVAL: " << m_value
              << " WG: " << m_weight << std::endl;
}

void Ammo::setCount(int count)
{
    m_count = count;
}

int Ammo::getCount() const
{
    return m_count;
}

int Ammo::getStack() const
{
    return m_stack;
}

std::string Ammo::getTags() const
{
    return m_tags;
}
