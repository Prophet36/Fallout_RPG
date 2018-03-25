#pragma once

#include "Armor.h"
#include "Item.h"
#include "RangedWeapon.h"
#include <string>   // std::string
#include <vector>   // std::vector

/**
 * Global value for character's inventory size.
 */
const int c_inventory_size = 3;

/**
 * This is a class for character inventory and general inventory management. It
 * contains members and methods for managing both particular character's
 * inventory and static methods for general inventory and item type management.
 *
 * @author Mateusz Warchol
 * @see Item
 */
class Inventory
{
public:
    /**
     * Enumerator containing values corresponding to item types.
     */
    enum { CONSUMABLE, WEAPON, AMMO, ARMOR };

    /**
     * Enumerator containing values corresponding to weapon types.
     */
    enum { MELEE, RANGED };

    /**
     * Enumerator containing values corresponding to ammunition types.
     */
    enum { PISTOL_SMALL, PISTOL_LARGE, REVOLVER_SMALL, REVOLVER_LARGE,
           SHOTGUN_SMALL, SHOTGUN_LARGE, RIFLE_SMALL, RIFLE_LARGE, RIFLE_SNIPER,
           ENERGY };

public:
    /**
     * Class constructor. Creates instance of Inventory object while specifying
     * inventory size (defaults to global inventory size value) and adds
     * default items.
     *
     * @param max_space size of inventory, also known as number of available
     *                  slots in inventory
     */
    Inventory(int max_space = c_inventory_size);

    /**
     * Copy constructor is inaccessible.
     */
    Inventory(const Inventory & rhs) = delete;

    /**
     * Class destructor. Deletes instance of Inventory object along with all
     * its contents.
     */
    ~Inventory();

    /**
     * Assignment operator is inaccessible.
     */
    void operator=(const Inventory & rhs) = delete;

    /**
     * Finds and checks correct item prefix in provided item ID.
     *
     * @param item_id   string containing item ID
     * @return          enumerator value representing item type when item ID
     *                  is correct, otherwise -1
     */
    static int checkItemPrefix(std::string item_id);

    /**
     * Finds and checks correct attribute the consumable item bonus applies to
     * in provided bonus string.
     *
     * @param bonus string containing the name of attribute
     * @return      enumerator value representing type of character attribute
     *              the consumable applies bonus to when provided bonus is
     *              correct, otherwise -1
     * @see         Consumable
     */
    static int checkConsumableBonus(std::string bonus);

    /**
     * Finds and checks correct weapon type in provided item tags.
     *
     * @param tags  string containing item tags
     * @return      enumerator value representing weapon type when tags are
     *              correct, otherwise -1
     */
    static int checkWeaponType(std::string tags);

    /**
     * Finds and checks for correct ammunition type in provided item tags.
     *
     * @param tags  string containing item tags
     * @return      enumerator value representing ammunition type when tags are
     *              correct, otherwise -1
     */
    static int checkAmmoType(std::string tags);

    /**
     * Prints out contents of character's inventory, with the option to
     * additionally print equipped items.
     *
     * @param equipped  also prints equipped items if true, otherwise prints
     *                  only the contents of inventory
     */
    void print(bool equipped = false) const;

    /**
     * Adds specified item to character's inventory. Calls remove() after adding
     * new item, if it surpasses inventory size limit and flag to ignore limit
     * is false.
     *
     * @param item_id       ID of the item to add to inventory
     * @param ignore_limit  ignores inventory size limit if true, otherwise
     *                      checks inventory size after adding item
     * @param count         how much of particular item should be created in one
     *                      stack (applies only to items that can be stacked in
     *                      one inventory slot, otherwise is ignored)
     */
    void add(std::string item_id, bool ignore_limit = false, int count = 0);

    /**
     * Prompts the user to remove item from one inventory slot.
     */
    void remove();

    /**
     * Prompts the user to equip item from inventory.
     */
    void equip();

    /**
     * Prompts the user to unequip item and move it back to inventory.
     */
    void unequip();

    /**
     * Prompts the user to reload weapon.
     */
    void reloadWeapon();

    /**
     * Prompts the user to unload weapon.
     */
    void unloadWeapon();

    /**
     * Warns the user when all inventory slots are already filled while
     * prompting to proceed.
     *
     * @return  true if user wants to proceed, otherwise false
     */
    bool warnEncumbrance() const;

    /**
     * Returns pointer to Item object containing equipped weapon.
     *
     * @return  pointer to Item object, which represents equipped weapon
     */
    Item * getWeapon() const { return m_weapon; }

    /**
     * Returns pointer to Armor object containing equipped armor.
     *
     * @return  pointer to Armor object, which represents equipped armor
     */
    Armor * getArmor() const { return dynamic_cast<Armor *>(m_armor); }

private:
    /**
     * Checks for stackable item of the same type that has been added to
     * inventory in order to sort the stacks. If possible, moves new stack of
     * the item to previously added slot of the same item, otherwise fills
     * previous stack and fills new slot with the remaining count.
     *
     * @param created_item  pointer to Item object added to inventory
     */
    void sort(Item * created_item);

    /**
     * Prints out character's equipped items.
     *
     * @param list_start    value from which the list starts being numbered 
     */
    void printEquipped(int list_start = 1) const;

    /**
     * Equips item from specified inventory slot to hand (if equipping weapon)
     * or body (if equipping armor), swapping already equipped item back to
     * inventory.
     *
     * @param slot  inventory slot from which the item is equipped
     */
    void equip(int slot);

    /**
     * Equips weapon from specified inventory slot to hand, swapping already
     * equipped weapon back to inventory.
     *
     * @param slot  inventory slot from which the weapon is equipped
     */
    void equipWeapon(int slot);

    /**
     * Equips armor from specified inventory slot to body, swapping already
     * equipped armor back to inventory.
     *
     * @param slot  inventory slot from which the armor is equipped
     */
    void equipArmor(int slot);

    /**
     * Unequips specified item, moving it back to inventory.
     *
     * @param slot  equippable slot from which the item is unequipped
     */
    void unequip(int slot);

    /**
     * Checks for appropriate ammunition inside inventory in order to reload
     * chosen weapon.
     *
     * @param slot  inventory slot containing weapon to reload
     */
    void reloadWeapon(int slot);

    /**
     * Reloads specified weapon with ammunition found in inventory.
     *
     * @param weapon    pointer to RangedWeapon object, representing weapon to
     *                  reload with ammunition
     * @param slot      inventory slot containing appropriate ammunition
     */
    void reloadWeapon(RangedWeapon * weapon, int slot);

    /**
     * Unloads all ammunition from the magazine from specified weapon, putting
     * the ammunition back in inventory.
     *
     * @param slot  inventory slot containing weapon to unload ammo from
     */
    void unloadWeapon(int slot);

    /**
     * Checks whether inventory is over maximum capacity (per inventory slots).
     *
     * return   true if inventory is over maximum slot capacity, otherwise false
     */
    bool checkEncumbrance() const;

    /**
     * Finds and checks correct item type in provided item tags.
     *
     * @param tags  string containing item tags
     * @return      enumerator value representing item type when tags are
     *              correct, otherwise -1
     */
    int checkItemType(std::string tags);

private:
    /**
     * Value specifying maximum inventory capacity (number of inventory slots).
     */
    int m_max_space;

    /**
     * Vector of pointers to Item objects. Stores pointers to those objects in
     * character's inventory, representing current items in character's
     * inventory.
     */
    std::vector<Item *> m_items;

    /**
     * Pointer to Item object representing equipped weapon.
     */
    Item * m_weapon;

    /**
     * Pointer to Item object representing equipped armor.
     */
    Item * m_armor;
};
