// Factory for item class objects

#pragma once

#include "Item.h"
#include <string>   // std::string

class FItem
{
public:
    static Item * createNewItem(std::string item_id);

private:
    FItem();
    ~FItem();

    static Item * createNewConsumable();
    static Item * createNewWeapon();
    static Item * createNewMeleeWeapon(std::string tags);
    static Item * createNewRangedWeapon(std::string tags);
    static Item * createNewAmmo();
    static Item * createNewArmor();
};
