// Character-derived class for human characters

#pragma once

#include "Armor.h"
#include "Character.h"
#include "Consumable.h"
#include "Inventory.h"
#include "Item.h"
#include <string>   // std::string
#include <vector>   // std::vector

class Human : public Character
{
public:
    Human(int max_space = 10);
    ~Human();

    void showInventory() const;
    void addItemPrompt(std::string item_id);
    void deleteItemPrompt();
    bool checkInventorySpace(bool adding_item = true) const;

protected:
    std::vector<Item *> inventory;
    int m_max_space;
};
