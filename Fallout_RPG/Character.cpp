#include "stdafx.h"
#include "Character.h"
#include "Inventory.h"
#include <iostream>

Character::Character(std::string name, int level, int strength, int agility,
                     int vitality, int perception, int intelligence, int luck) :
    m_name(name), m_level(level), m_strength(strength), m_agility(agility),
    m_vitality(vitality), m_perception(perception),
    m_intelligence(intelligence), m_luck(luck)
{
    m_inventory = nullptr;
    m_health = getMaxHealth();
    std::cout << "DEBUG: ----- Character " << m_name << " created! ----- \n";
}

Character::~Character()
{
    delete m_inventory;
    std::cout << "DEBUG: ----- Character " << m_name << " destroyed! ----- \n";
}
