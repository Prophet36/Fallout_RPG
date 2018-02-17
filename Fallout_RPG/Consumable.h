#pragma once

#include "IStackable.h"
#include "Item.h"

/**
 * This class is for consumable type objects. It inherits from Item class,
 * particularly members and methods common to all items in the game, and from
 * IStackable interface class for managing stacks of consumables in inventory
 * slots.
 *
 * This class contains description and statistics (attributes) for particular
 * instances of Consumable objects, to differientiate between different
 * consumables. Its methods consist of printing those statistics
 * and manipulating the count of particular consumable in one inventory slot.
 *
 * @author  Mateusz Warchol
 * @version 1.0, 02/10/18
 * @see     Item
 * @see     IStackable
 */
class Consumable : public Item, public IStackable
{
public:


    enum { STRENGTH, ENDURANCE, AGILITY, PERCEPTION, INTELLIGENCE, LUCK,
           HEALTH, RADS };

public:
    /**
     * Class constructor. Creates instance of Consumable object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param attribute     enumerator representing type of character attribute
     *                      to modify
     * @param magnitude     value specifying how much the attribute is modified
     * @param duration      value specifying how long (in game turns)
     *                      the attribute is modified. Value of 0 means
     *                      the attribute change is permanent.
     * @param count         current count of this object in one inventory slot
     * @param stack         maximum count of this object in one inventory slot
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    Consumable(std::string name, std::string description, int attribute,
               int magnitude, int duration, int count, int stack, int value,
               double weight, std::string tags);

    /**
     * Class desctructor. Deletes instance of Consumable object.
     */
    ~Consumable();

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

private:
    /**
     * Type of character attribute the consumable is modifying.
     */
    int m_attribute;

    /**
     * Specifies how much the attribute is modified.
     */
    int m_magnitude;
    
    /**
     * Specifies how long the attribute is modified, measured in game turns.
     * After this amount of turns pass, modified attribute reverts to its
     * original value. When set to 0, the attribute is modified permanently,
     * unless changed by a different source at later time.
     */
    int m_duration;
};
