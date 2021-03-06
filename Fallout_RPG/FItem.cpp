#include "stdafx.h"
#include "Ammo.h"
#include "Armor.h"
#include "Consumable.h"
#include "CritterWeapon.h"
#include "File.h"
#include "FItem.h"
#include "Input.h"
#include "Inventory.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "RangedWeapon.h"
#include <iostream>
#include <string>

Item * FItem::createNewItem(std::string item_id, int count)
{
    switch (Inventory::checkItemPrefix(item_id))
    {
        case Inventory::CONSUMABLE:
        {
            return createNewConsumable(count);
        }
        case Inventory::WEAPON:
        {
            return createNewWeapon();
        }
        case Inventory::AMMO:
        {
            return createNewAmmo(count);
        }
        case Inventory::ARMOR:
        {
            return createNewArmor();
        }
        default:
        {
            std::cerr << "ERROR: Incorrect item type!\n";
            return new Consumable("Dummy Item", "Dummy item.", 0, 0, 0, 1, 1, 0,
                                  0.0, "item");
        }
    }
}

Item * FItem::createNewConsumable(int count)
{
    File * working_file = File::get(c_items);
    std::string tags = working_file->getString();
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    int attribute = Inventory::checkConsumableBonus(working_file->getString());
    int magnitude = working_file->getInt();
    int duration = working_file->getInt();
    int stack = working_file->getInt();
    int value = working_file->getInt();
    double weight = working_file->getDouble();

    if (count <= 0 || count > stack)
    {
        std::cout << "How many do you want to add? ";
        count = Input::switchPrompt(1, stack);
    }

    return new Consumable(name, description, attribute, magnitude, duration,
                          count, stack, value, weight, tags);
}

Item * FItem::createNewWeapon()
{
    std::string tags = File::get(c_items)->getString();
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
        case Inventory::CRITTER:
        {
            return createNewCritterWeapon(tags);
        }
        default:
        {
            return new RangedWeapon("Dummy Gun", "Dummy gun.", "blanks",
                                    "Blanks", 0, 0, "d4", 0, 0, 0, 0, 0, 0.0,
                                    "ranged, gun, short");
        }
    }
}

Item * FItem::createNewMeleeWeapon(std::string tags)
{
    File * working_file = File::get(c_items);
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    int damage = working_file->getInt();
    std::string roll = working_file->getString();
    int speed = working_file->getInt();
    int penetration = working_file->getInt();
    int requirement = working_file->getInt();
    int value = working_file->getInt();
    double weight = working_file->getDouble();

    return new MeleeWeapon(name, description, damage, roll, speed, penetration,
                           requirement, value, weight, tags);
}

Item * FItem::createNewRangedWeapon(std::string tags)
{
    File * working_file = File::get(c_items);
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    std::string ammo_type = working_file->getString();
    std::string ammo = working_file->getString();
    int capacity = working_file->getInt();
    int damage = working_file->getInt();
    std::string roll = working_file->getString();
    int speed = working_file->getInt();
    int accuracy = working_file->getInt();
    int penetration = working_file->getInt();
    int requirement = working_file->getInt();
    int value = working_file->getInt();
    double weight = working_file->getDouble();

    return new RangedWeapon(name, description, ammo_type, ammo, capacity,
                            damage, roll, speed, accuracy, penetration,
                            requirement, value, weight, tags);
}

Item * FItem::createNewCritterWeapon(std::string tags)
{
    File * working_file = File::get(c_items);
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    int damage = working_file->getInt();
    std::string roll = working_file->getString();
    int speed = working_file->getInt();
    int accuracy = working_file->getInt();
    int penetration = working_file->getInt();
    int rads = working_file->getInt();
    int poison_chance = working_file->getInt();
    int poison_damage = working_file->getInt();
    int poison_duration = working_file->getInt();

    return new CritterWeapon(name, description, damage, roll, speed, accuracy,
                             penetration, rads, poison_chance, 5,
                             poison_duration, tags);
}

Item * FItem::createNewAmmo(int count)
{
    File * working_file = File::get(c_items);
    std::string tags = working_file->getString();
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    int stack = working_file->getInt();
    int value = working_file->getInt();
    double weight = working_file->getDouble();

    if (count <= 0 || count > stack)
    {
        std::cout << "How many do you want to add? ";
        count = Input::switchPrompt(1, stack);
    }

    return new Ammo(name, description, count, stack, value, weight, tags);
}

Item * FItem::createNewArmor()
{
    File * working_file = File::get(c_items);
    std::string tags = working_file->getString();
    std::string name = working_file->getString();
    std::string description = working_file->getString();
    int reduction = working_file->getInt();
    int evasion = working_file->getInt();
    int protection = working_file->getInt();
    int value = working_file->getInt();
    double weight = working_file->getDouble();

    return new Armor(name, description, reduction, evasion, protection,
                     value, weight, tags);
}
