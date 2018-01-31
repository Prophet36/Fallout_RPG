#include "stdafx.h"
#include "Ammo.h"
#include "Armor.h"
#include "Consumable.h"
#include "File.h"
#include "FItem.h"
#include "Input.h"
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

Item * FItem::createNewItem(std::string item_id)
{
    switch (Inventory::checkItemPrefix(item_id))
    {
        case Inventory::CONSUMABLE:
        {
            return createNewConsumable();
        }
        case Inventory::WEAPON:
        {
            return createNewWeapon();
        }
        case Inventory::AMMO:
        {
            return createNewAmmo();
        }
        case Inventory::ARMOR:
        {
            return createNewArmor();
        }
        default:
        {
            std::cerr << "ERROR: Incorrect item type!\n";
            return new Consumable("Dummy Item", "Dummy item.", 0, 0, 0, 0, 0.0);
        }
    }
}


Item * FItem::createNewConsumable()
{
    std::string name = File::open()->getString();
    std::string description = File::open()->getString();
    int attribute = Inventory::checkConsumableBonus(File::open()->getString());
    int magnitude = File::open()->getInt();
    int duration = File::open()->getInt();
    int value = File::open()->getInt();
    double weight = File::open()->getDouble();

    return new Consumable(name, description, attribute, magnitude, duration,
                          value, weight);
}

Item * FItem::createNewWeapon()
{
    std::string tags = File::open()->getString();
    switch (Inventory::checkWeaponType(tags))
    {
        case Inventory::MELEE:
        {
            return createNewMeleeWeapon(tags);
        }
        case Inventory::RANGED:
        {
            return createNewRangedWeapon(tags);
        }
        default:
        {
            return new RangedWeapon("Dummy Gun", "Dummy gun.", 0, 0, 0, "d4",
                                    0, 0, 0, 0, 0, 0.0, "ranged, gun, short");
        }
    }
}

Item * FItem::createNewMeleeWeapon(std::string tags)
{
    std::string name = File::open()->getString();
    std::string description = File::open()->getString();
    int damage = File::open()->getInt();
    std::string roll = File::open()->getString();
    int speed = File::open()->getInt();
    int penetration = File::open()->getInt();
    int requirement = File::open()->getInt();
    int value = File::open()->getInt();
    double weight = File::open()->getDouble();

    return new MeleeWeapon(name, description, damage, roll, speed, penetration,
                           requirement, value, weight, tags);
}

Item * FItem::createNewRangedWeapon(std::string tags)
{
    std::string name = File::open()->getString();
    std::string description = File::open()->getString();
    int ammo_type = Inventory::checkAmmoType(File::open()->getString());
    int capacity = File::open()->getInt();
    int damage = File::open()->getInt();
    std::string roll = File::open()->getString();
    int speed = File::open()->getInt();
    int accuracy = File::open()->getInt();
    int penetration = File::open()->getInt();
    int requirement = File::open()->getInt();
    int value = File::open()->getInt();
    double weight = File::open()->getDouble();

    return new RangedWeapon(name, description, ammo_type, capacity, damage,
                            roll, speed, accuracy, penetration, requirement,
                            value, weight, tags);
}

Item * FItem::createNewAmmo()
{
    std::string name = File::open()->getString();
    std::string description = File::open()->getString();
    int stack = File::open()->getInt();

    std::cout << "How many ammunition you want to add? ";
    int current_count = Input::getInt();

    int value = File::open()->getInt();
    double weight = File::open()->getDouble();

    return new Ammo(name, description, stack, current_count, value, weight);
}

Item * FItem::createNewArmor()
{
    std::string name = File::open()->getString();
    std::string description = File::open()->getString();
    int reduction = File::open()->getInt();
    int evasion = File::open()->getInt();
    int protection = File::open()->getInt();
    int value = File::open()->getInt();
    double weight = File::open()->getDouble();

    return new Armor(name, description, reduction, evasion, protection,
                     value, weight);
}

FItem::~FItem()
{
}
