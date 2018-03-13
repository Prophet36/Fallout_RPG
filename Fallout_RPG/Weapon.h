#pragma once

#include <string>   // std::string
#include "Item.h"

/**
 * This class is for general weapon type objects. It inherits from Item class,
 * particularly members and methods common to all items in the game.
 *
 * This class contains description and statistics (attributes) common to all
 * Weapon objects. Its methods consist of printing those statistics as well as
 * returning particular attributes.
 *
 * @author  Mateusz Warchol
 * @see     Item
 * @see     MeleeWeapon
 * @see     RangedWeapon
 */
class Weapon : public Item
{
public:
    /**
     * Class constructor. Creates instance of Weapon object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param damage        value specifying weapon's base damage
     * @param roll          string containing type of dice roll for additional
     *                      damage
     * @param speed         value specifying weapon speed in turn-based attacks
     * @param penetration   value specifying ability to negate enemy's armor
     *                      when attacking
     * @param requirement   value specifying minimum strength needed to wield
     *                      the weapon
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    Weapon(std::string name, std::string description, int damage,
           std::string roll, int speed, int penetration, int requirement,
           int value, double weight, std::string tags);

    /**
     * Class desctructor. Deletes instance of Weapon object.
     */
    virtual ~Weapon();

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const = 0;

    /**
     * Returns minimum amount of damage the weapon can do.
     *
     * @return  value specifying the least amount of damage the weapon can do
     *          when rolling the lowest number for damage
     */
    int getMinDamage() const;

    /**
     * Returns maximum amount of damage the weapon can do.
     *
     * @return  value specifying highest potential damage the weapon can do
     *          when rolling the highest number for damage
     */
    int getMaxDamage() const;

protected:
    /**
     * Specifies dice roll for additional damage the weapon can do. Format for
     * this roll is XdY, where X is the number of dice rolls of Y-sided dice
     * (if only one roll is to be made X is omitted, instead of being 1).
     */
    std::string m_roll;

    /**
     * Value specifying how much base damage the weapon does.
     */
    int m_damage;

    /**
     * Value specifying how fast the weapon attacks. Stacks with character's
     * innate speed to determine turn order in one round of combat.
     */
    int m_speed;

    /**
     * Value specifying how much opponent's armor the weapon's attack ignores.
     * If penetration is greater than opponent's armor reduction value, then
     * the attack will ignore armor completely.
     */
    int m_penetration;

    /**
     * Value specifying amount of character's strength attribute required to
     * wield this weapon.
     */
    int m_requirement;
};
