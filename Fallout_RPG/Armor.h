#pragma once

#include "Item.h"

/**
 * This class is for armor type objects. It inherits from Item class,
 * particularly members and methods common to all items in the game.
 *
 * This class contains description and statistics (attributes) for particular
 * instances of Armor objects, to differientiate between different armors.
 * Its method consist of printing those statistics.
 *
 * @author  Mateusz Warchol
 * @see     Item
 */
class Armor :
    public Item
{
public:
    /**
     * Class constructor. Creates instance of Armor object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param reduction     maximum potential damage reduction
     * @param evasion       possible bonus (or malus, if negative) to attack
     *                      evasion
     * @param protection    radiation protection, measured in %
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    Armor(std::string name, std::string description, int reduction, int evasion,
          int protection, int value, double weight, std::string tags);

    /**
     * Default class destructor. Deletes instance of Armor object.
     */
    virtual ~Armor() = default;

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;

    /**
     * Returns the armor's damage reduction value.
     *
     * @return  damage reduction provided by this armor
     */
    int getReduction() const { return m_reduction; }

    /**
     * Returns the armor's evasion value.
     *
     * @return  bonus (or malus) attack evasion provided by this armor
     */
    int getEvasion() const { return m_evasion; }

    /**
     * Returns the armor's protection value.
     *
     * @return  radiation protection provided by this armor
     */
    int getProtection() const { return m_protection; }

private:
    /**
     * Value specifying maximum possible damage reduction of incoming attack.
     */
    int m_reduction;

    /**
     * Potential bonus (or malus, if negative) to attack evasion. Stacks with
     * innate character evasion.
     */
    int m_evasion;

    /**
     * Radiation protection. Absorbs specified percent of rads. Measured in %.
     */
    int m_protection;
};
