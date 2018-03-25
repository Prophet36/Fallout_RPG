#include "stdafx.h"
#include "Character.h"
#include <iostream>

Character::Character(std::string name) :
    m_name(name)
{
    std::cout << "DEBUG: ----- Character " << m_name << " created! ----- \n";
}

Character::~Character()
{
    std::cout << "DEBUG: ----- Character " << m_name << " destroyed! ----- \n";
}
