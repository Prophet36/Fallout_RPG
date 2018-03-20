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
 * @see     Item
 * @see     IStackable
 */
class Consumable : public Item, public IStackable
{
public:
    /**
     * Enumerator containing values corresponding to attributes being modified.
     */
    enum { STRENGTH, ENDURANCE, AGILITY, PERCEPTION, INTELLIGENCE, LUCK,
           HEALTH, RADS };

public:
    /**
     * Class constructor. Creates instance of Consumable object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param attribute     enumerator value representing type of character
     *                      attribute to modify
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
     * Default class destructor. Deletes instance of Consumable object.
     */
    virtual ~Consumable() = default;

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;

private:
    /**
     * Type of character attribute the consumable is modifying, according to
     * enumerator provided with this class.
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
     * unless changed by a different source at a later time.
     */
    int m_duration;
};
