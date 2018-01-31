// Factory for item class objects

#pragma once

#include "Item.h"
#include <string>   // std::string

class FItem
{
public:
    static Item * createNewItem(std::string item_id, int item_position);

private:
    FItem();
    ~FItem();

    static Item * createNewConsumable(int item_position);
    static Item * createNewWeapon(int item_position);
    static Item * createNewMeleeWeapon(int item_position);
    static Item * createNewRangedWeapon(int item_position);
    static Item * createNewAmmo(int item_position);
    static Item * createNewArmor(int item_position);
};
