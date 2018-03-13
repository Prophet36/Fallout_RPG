#pragma once

#include "Item.h"
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
     * Enumerator containing values corresponding item types.
     */
    enum { CONSUMABLE, WEAPON, AMMO, ARMOR };

    /**
     * Enumerator containing values corresponding weapon types.
     */
    enum { MELEE, RANGED };

public:
    /**
     * Class constructor. Creates instance of Inventory object while specifying
     * inventory size (defaults to global inventory size value).
     *
     * @param max_space size of inventory, also known as number of available
     *                  slots in inventory
     */
    Inventory(int max_space = c_inventory_size);

    /**
     * Class destructor. Deletes instance of Inventory object along with all
     * its contents.
     */
    ~Inventory();

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
     * Prints out contents of character's inventory.
     */
    void print() const;

    /**
     * Adds specified item to character's inventory. Calls remove() after adding
     * new item, if it surpasses inventory size limit.
     *
     * @param item_id   ID of the item to add to inventory
     */
    void add(std::string item_id);

    /**
     * Prompts the user to remove item from one inventory slot.
     */
    void remove();

    /**
     * Warns the user when all inventory slots are already filled while
     * prompting to proceed.
     *
     * @return  true if user wants to proceed, otherwise false
     */
    bool warnEncumbrance() const;

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
     * Checks whether inventory is over maximum capacity (per inventory slots).
     *
     * return   true if inventory is over maximum slot capacity, otherwise false
     */
    bool checkEncumbrance() const;

private:
    /**
     * Value specifying maximum inventory capacity (number of inventory slots).
     */
    int m_max_space;

    /**
     * Vector of pointers to Item objects. Stores pointers to those objects in
     * character's inventory.
     */
    std::vector<Item *> m_items;
};
