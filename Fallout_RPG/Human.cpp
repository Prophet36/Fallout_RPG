#include "stdafx.h"
#include "Human.h"
#include "Inventory.h"

Human::Human()
{
    m_inventory = new Inventory();
}

Human::~Human()
{
    delete m_inventory;
}
