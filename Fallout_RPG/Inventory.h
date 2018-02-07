// Static class for inventory management and utility

#pragma once

#include <string>   // std::string

class Inventory
{
public:
    enum { CONSUMABLE, WEAPON, AMMO, ARMOR };
    enum { MELEE, RANGED };
    enum { PISTOL_SMALL, PISTOL_LARGE, REVOLVER_SMALL, REVOLVER_LARGE,
           SHOTGUN_SMALL, SHOTGUN_LARGE, RIFLE_SMALL, RIFLE_LARGE, RIFLE_SNIPER,
           ENERGY };

public:
    static int checkItemPrefix(std::string item_id);
    static int checkConsumableBonus(std::string bonus);
    static int checkWeaponType(std::string tags);
    static int checkAmmoType(std::string tags);

private:
    Inventory();
    ~Inventory();
};
