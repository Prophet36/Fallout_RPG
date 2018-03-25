#include "stdafx.h"
#include "Human.h"
#include "Inventory.h"

Human::Human(std::string name) :
    Character(name)
{
    m_inventory = new Inventory();
}

Human::~Human()
{
    delete m_inventory;
}
