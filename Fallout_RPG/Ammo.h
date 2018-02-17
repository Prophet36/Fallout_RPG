#pragma once

#include "IStackable.h"
#include "Item.h"
#include <string>   // std::string

/**
 * This class is for ammunition (ammo) type objects. It inherits from Item
 * class, particularly members and methods common to all items in the game,
 * and from IStackable interface class for managing stacks of ammunition in
 * inventory slots.
 *
 * This class contains description and statistics (attributes) for particular
 * instances of Ammo objects, to differientiate between different ammo types.
 * Its methods consist of printing those statistics and manipulating the count
 * of particular ammo type in one inventory slot.
 *
 * @author  Mateusz Warchol
 * @version 1.0, 02/10/18
 * @see     Item
 * @see     IStackable
 */
class Ammo :
    public Item, public IStackable
{
public:
    /**
     * Class constructor. Creates instance of Ammo object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param count         current count of this object in one inventory slot
     * @param stack         maximum count of this object in one inventory slot
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    Ammo(std::string name, std::string description, int count, int stack,
         int value, double weight, std::string tags);

    /**
     * Class desctructor. Deletes instance of Ammo object.
     */
    ~Ammo();

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;

    /**
     * Sets current count of the object in one inventory slot. If the value
     * to set current count to is greater than maximum possible count (m_stack)
     * in one slot, then returns the amount that is over the limit, otherwise
     * returns 0.
     *
     * @param count value to set the current count to
     * @return      amount over the maximum possible count if setting count
     *              to a higher value than maximum possible count in one
     *              inventory slot, otherwise 0
     */
    virtual int setCount(int count) override;

    /**
     * Returns current count of the object in one inventory slot.
     *
     * @return  current count in one inventory slot
     */
    virtual int getCount() const override;

    /**
     * Returns the object's tags field.
     *
     * @return  string containing tags associated with the object
     */
    virtual std::string getTags() const override;
};
