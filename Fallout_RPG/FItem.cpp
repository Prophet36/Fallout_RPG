#include "stdafx.h"
#include "Armor.h"
#include "Consumable.h"
#include "File.h"
#include "FItem.h"
#include "Inventory.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "RangedWeapon.h"
#include <fstream>  // std::fstream
#include <iostream> // std::cout, std::cerr
#include <string>   // std::string

FItem::FItem()
{
}

Item * FItem::createNewItem(std::string item_id, int item_position)
{
    switch (Inventory::checkItemPrefix(item_id))
    {
        case Inventory::CONSUMABLE:
        {
            return createNewConsumable(item_position);
            break;
        }
        case Inventory::WEAPON:
        {
            return createNewWeapon(item_position);
            break;
        }
        case Inventory::ARMOR:
        {
            return createNewArmor(item_position);
            break;
        }
        default:
        {
            std::cerr << "ERROR: Incorrect item type!\n";
            return new Consumable("Dummy Item", "Dummy item.", 0, 0, 0, 0, 0.0);
        }
    }
}


Item * FItem::createNewConsumable(int item_position)
{
    std::fstream w_file = File::openFileAt(item_position, ITEMS);

    std::string name = File::getString(w_file);
    std::string description = File::getString(w_file);
    int attribute = Inventory::checkConsumableBonus(File::getString(w_file));
    int magnitude = File::getInt(w_file);
    int duration = File::getInt(w_file);
    int value = File::getInt(w_file);
    double weight = File::getDouble(w_file);

    File::closeFile(w_file);

    return new Consumable(name, description, attribute, magnitude, duration,
                          value, weight);
}

Item * FItem::createNewWeapon(int item_position)
{
    std::fstream w_file = File::openFileAt(item_position, ITEMS);

    int type = Inventory::checkWeaponType(File::getString(w_file));
    File::closeFile(w_file);
    switch (type)
    {
        case Inventory::MELEE:
        {
            return createNewMeleeWeapon(item_position);
        }
        case Inventory::RANGED:
        {
            return createNewRangedWeapon(item_position);
        }
        default:
        {
            return new RangedWeapon("Dummy Gun", "Dummy gun.", 0, 0, 0, "d4",
                                    0, 0, 0, 0, 0, 0.0, "ranged, gun, short");
        }
    }
}

Item * FItem::createNewMeleeWeapon(int item_position)
{
    std::fstream w_file = File::openFileAt(item_position, ITEMS);

    std::string tags = File::getString(w_file);
    std::string name = File::getString(w_file);
    std::string description = File::getString(w_file);
    int damage = File::getInt(w_file);
    std::string roll = File::getString(w_file);
    int speed = File::getInt(w_file);
    int penetration = File::getInt(w_file);
    int requirement = File::getInt(w_file);
    int value = File::getInt(w_file);
    double weight = File::getDouble(w_file);

    File::closeFile(w_file);

    return new MeleeWeapon(name, description, damage, roll, speed, penetration,
                           requirement, value, weight, tags);
}

Item * FItem::createNewRangedWeapon(int item_position)
{
    std::fstream w_file = File::openFileAt(item_position, ITEMS);

    std::string tags = File::getString(w_file);
    std::string name = File::getString(w_file);
    std::string description = File::getString(w_file);
    int ammo_type = Inventory::checkAmmoType(File::getString(w_file));
    int capacity = File::getInt(w_file);
    int damage = File::getInt(w_file);
    std::string roll = File::getString(w_file);
    int speed = File::getInt(w_file);
    int accuracy = File::getInt(w_file);
    int penetration = File::getInt(w_file);
    int requirement = File::getInt(w_file);
    int value = File::getInt(w_file);
    double weight = File::getDouble(w_file);

    File::closeFile(w_file);

    return new RangedWeapon(name, description, ammo_type, capacity, damage,
                            roll, speed, accuracy, penetration, requirement,
                            value, weight, tags);
}

Item * FItem::createNewArmor(int item_position)
{
    std::fstream w_file = File::openFileAt(item_position, ITEMS);

    std::string name = File::getString(w_file);
    std::string description = File::getString(w_file);
    int reduction = File::getInt(w_file);
    int evasion = File::getInt(w_file);
    int protection = File::getInt(w_file);
    int value = File::getInt(w_file);
    double weight = File::getDouble(w_file);

    File::closeFile(w_file);

    return new Armor(name, description, reduction, evasion, protection,
                     value, weight);
}

FItem::~FItem()
{
}
