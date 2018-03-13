#pragma once

#include "Item.h"
#include <string>   // std::string

/**
 * This is class is responsible for creating objects of Item class, along with
 * classes that inherit from base Item class. Its methods consist of creating
 * and returning instances of particular items, while getting particular
 * parameters of those objects from attached files.
 *
 * The class can't be instantiated and all its methods are static in order to
 * be able to freely use those methods whenever new items creation is needed.
 *
 * @author  Mateusz Warchol
 * @see     File
 * @see     Item
 */
class FItem
{
public:
    /**
     * Creates and returns pointer to specified Item object based on its item
     * ID. If the ID is incorrect, it returns pointer to default 'dummy' item.
     *
     * @param item_id   ID of the item to create
     * @return          pointer to new Item object matching ID
     */
    static Item * createNewItem(std::string item_id);

private:
    /**
     * Private class constructor. Can't be called.
     */
    FItem();

    /**
     * Private class desctructor. Can't be called.
     */
    ~FItem();

    /**
     * Creates and returns pointer to Consumable object, while asking user to
     * input amount of particular consumable to create.
     *
     * @return  pointer to new Item class consumable type object
     */
    static Item * createNewConsumable();

    /**
     * Creates and returns pointer to Weapon object. If the weapon type is
     * incorrect, it returns pointer to default 'dummy' weapon.
     *
     * @return  pointer to new Item class weapon type object
     */
    static Item * createNewWeapon();

    /**
     * Creates and returns pointer to MeleeWeapon object.
     *
     * @param tags  string containing tags of object to create
     * @return      pointer to new Item class melee weapon type object
     */
    static Item * createNewMeleeWeapon(std::string tags);

    /**
     * Creates and returns pointer to RangedWeapon object.
     *
     * @param tags  string containing tags of object to create
     * @return      pointer to new Item class ranged weapon type object
     */
    static Item * createNewRangedWeapon(std::string tags);

    /**
     * Creates and returns pointer to Ammo object, while asking the user to
     * input amount of particular ammunition to create.
     *
     * @return  pointer to new Item class ammunition type object
     */
    static Item * createNewAmmo();

    /**
     * Creates and returns pointer to Armor object.
     *
     * @return  pointer to new Item class armor type object
     */
    static Item * createNewArmor();
};
