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
 * @version 1.01, 22/02/18
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
};
