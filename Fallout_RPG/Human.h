#pragma once

#include "Character.h"
#include "Inventory.h"

/**
 * This class for human character objects. It inherits from Character class,
 * particularly members and methods common to all characters in the game.
 *
 * This class contains additional members and methods specific to humanoid
 * characters, like having an accessible inventory.
 *
 * @author  Mateusz Warchol
 * @see     Character
 * @see     Inventory
 */
class Human : public Character
{
public:
    /**
     * Class constructor. Creates instance of Human object.
     */
    Human();
    
    /**
     * Copy constructor is inaccessible.
     */
    Human(const Human &) = delete;

    /**
     * Class destructor. Deletes instance of Human object and its inventory.
     */
    virtual ~Human();

    /**
     * Assignment operator is inaccessible.
     */
    void operator=(const Human &) = delete;
    
    /**
     * Returns character's inventory, for further manipulation.
     *
     * @return  pointer to Inventory object, containing character's current
     *          inventory
     */
    Inventory * getInventory() const { return m_inventory; }

protected:
    /**
     * Contains character's inventory, represented as pointer to Inventory class
     * object.
     */
    Inventory * m_inventory;
};
