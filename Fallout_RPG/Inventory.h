// Static class for inventory management and utility

#pragma once

#include "Item.h"
#include <string>   // std::string
#include <vector>   // std::vector

const int c_inventory_size = 3;

class Inventory
{
public:
    enum { CONSUMABLE, WEAPON, AMMO, ARMOR };
    enum { MELEE, RANGED };
    enum { PISTOL_SMALL, PISTOL_LARGE, REVOLVER_SMALL, REVOLVER_LARGE,
           SHOTGUN_SMALL, SHOTGUN_LARGE, RIFLE_SMALL, RIFLE_LARGE, RIFLE_SNIPER,
           ENERGY };

public:
    Inventory(int max_space = c_inventory_size);
    ~Inventory();

    static int checkItemPrefix(std::string item_id);
    static int checkConsumableBonus(std::string bonus);
    static int checkWeaponType(std::string tags);
    static int checkAmmoType(std::string tags);

    void print() const;
    void add(std::string item_id);
    void remove();
    bool warnEncumbrance() const;
    bool checkEncumbrance() const;
    void sort(Item * created_item);

private:
    std::vector<Item *> m_items;
    int m_max_space;

};
