#pragma once

/**
 * This interface class is for objects that can be stacked in one inventory
 * slot, example being ammunition.
 *
 * This interface's members and methods consist of manipulating current
 * and maximum counts of the object's stack in one inventory slot.
 *
 * @author  Mateusz Warchol
 * @see     Ammo
 * @see     Consumable
 */
class IStackable
{
public:
    /**
     * Class constructor for inheritance purposes. Instance of inherited object
     * is constructed with specified parameters.
     *
     * @param count         current count of this object in one inventory slot
     * @param stack         maximum count of this object in one inventory slot
     */
    IStackable(int count, int stack);
    
    /**
     * Default class destructor. Deletes instance of Ammo object.
     */
    virtual ~IStackable() = default;

    /**
     * Sets current count of the object in one inventory slot. If the value
     * to set current count to is greater than maximum possible count (m_stack)
     * in one slot, then returns the amount that is over the limit, otherwise
     * returns 0.
     *
     * @param count value to set the current count to
     * @return      amount over the maximum possible count in one stack,
     *              if setting count to a value over stack maximum, otherwise 0
     */
    int setCount(int count);

    /**
     * Returns current count of the object in one inventory slot.
     *
     * @return  current count in one inventory slot
     */
    int getCount() const { return m_count; }

protected:
    /**
     * Current count of this object in one inventory slot.
     */
    int m_count;

    /**
     * Maximum possible count (stack size) of this object in one inventory slot.
     */
    int m_stack;
};
