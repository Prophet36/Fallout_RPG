#pragma once
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
    
    virtual ~IStackable();

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
    virtual int setCount(int count) = 0;

    /**
     * Returns current count of the object in one inventory slot.
     *
     * @return  current count in one inventory slot
     */
    virtual int getCount() const = 0;

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
