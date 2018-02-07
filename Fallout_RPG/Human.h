// Character-derived class for human characters

#pragma once

#include "Armor.h"
#include "Character.h"
#include "Consumable.h"
#include "Inventory.h"
#include "Item.h"
#include <string>   // std::string
#include <vector>   // std::vector

#define INVENTORY_SIZE 3

class Human : public Character
{
public:
    Human(int max_space = INVENTORY_SIZE);
    ~Human();

    void showInventory() const;
    void addItemPrompt(std::string item_id);
    void deleteItemPrompt();
    bool checkInventorySpace() const;
    bool checkInventoryEncumbrance() const;
    void sortInventory(Item * new_item);

protected:
    std::vector<Item *> inventory;
    int m_max_space;
};
