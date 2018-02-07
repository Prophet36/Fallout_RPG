#include "stdafx.h"
#include "Inventory.h"
#include <string>   // std::string

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

int Inventory::checkItemPrefix(std::string item_id)
{
    std::string prefixes[] = { "item_", "weapon_", "ammo_", "armor_" };

    for (int i = 0; i < (sizeof(prefixes) / sizeof(prefixes[0])); i++)
    {
        if (item_id.find(prefixes[i], 0) != std::string::npos)
        {
            return i;
        }
    }

    return -1;
}

int Inventory::checkConsumableBonus(std::string bonus)
{
    std::string bonuses[] = { "ST", "EN", "AG", "PE", "IN", "LK", "HP",
                              "RADS" };

    for (int i = 0; i < (sizeof(bonuses) / sizeof(bonuses[0])); i++)
    {
        if (bonus.find(bonuses[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}

int Inventory::checkWeaponType(std::string tags)
{
    std::string types[] = { "melee", "ranged" };

    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++)
    {
        if (tags.find(types[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}
int Inventory::checkAmmoType(std::string tags)
{
    std::string types[] = { "9mm", "45 ACP", ".357", ".44", "20ga", "12ga",
                            "5.56mm", ".308", "50 BMG", "EC" };

    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++)
    {
        if (tags.find(types[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}
