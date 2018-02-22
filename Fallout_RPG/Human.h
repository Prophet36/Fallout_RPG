// Character-derived class for human characters

#pragma once

#include "Character.h"
#include "Inventory.h"

class Human : public Character
{
public:
    Human();
    ~Human();

    Inventory * getInventory() const;

protected:
    Inventory * m_inventory;
};
