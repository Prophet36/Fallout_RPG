#pragma once

#include "Weapon.h"
#include <string>

/**
 * This class is for ranged weapon type objects. It inherits from Weapon class,
 * particularly members and methods common to all weapons in the game.
 *
 * This class contains description and statistics (attributes) describing ranged
 * weapons. Its methods consist of printing those statistics as well as
 * returning particular attributes.
 *
 * @author  Mateusz Warchol
 * @see     Weapon
 */
class RangedWeapon :
    public Weapon
{
public:
    /**
     * Class constructor. Creates instance of RangedWeapon object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param ammo_type     string containing ammunition type
     * @param ammo_name     string containing name of used ammunition
     * @param capacity      value specifying weapon's ammunition capacity in
     *                      magazine
     * @param damage        value specifying weapon's base damage
     * @param roll          string containing type of dice roll for additional
     *                      damage
     * @param speed         value specifying weapon speed in turn-based attacks
     * @param accuracy      value specifying bonus (or malus, if negative) to
     *                      accuracy when attacking with this weapon
     * @param penetration   value specifying ability to negate enemy's armor
     *                      when attacking
     * @param requirement   value specifying minimum strength needed to wield
     *                      the weapon
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    RangedWeapon(std::string name, std::string description,
                 std::string ammo_type, std::string ammo_name, int capacity,
                 int damage, std::string roll, int speed, int accuracy,
                 int penetration, int requirement, int value, double weight,
                 std::string tags);

    /**
     * Default class destructor. Deletes instance of RangedWeapon object.
     */
    virtual ~RangedWeapon() = default;

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;

    /**
     * Sets current count of ammunition in magazine.
     *
     * @param count current count of ammunition in weapon's magazine to set to
     */
    void setCurrentAmmo(int count) { m_current_ammo = count; }

    /**
     * Returns type of ammunition the weapon uses.
     *
     * @return  string containing ammunition type
     */
    std::string getAmmoType() const { return m_ammo_type; }

    /**
     * Returns ammunition capacity in magazine.
     *
     * @return  ammunition capacity in weapon's magazine
     */
    int getCapacity() const { return m_capacity; }

    /**
     * Returns current count of ammunition in magazine.
     *
     * @return  current count of ammunition in weapon's magazine
     */
    int getCurrentAmmo() const { return m_current_ammo; }
    
private:
    /**
     * Type of ammunition the weapon is using.
     */
    std::string m_ammo_type;

    /**
     * Full name of the ammunition the weapon is using.
     */
    std::string m_ammo_name;

    /**
     * Value specifying the weapon's magazine capacity.
     */
    int m_capacity;

    /**
     * Value specifying current amount of ammunition in magazine.
     */
    int m_current_ammo;

    /**
     * Potential bonus (or malus, if negative) to attack accuracy. Stacks with
     * innate character accuracy.
     */
    int m_accuracy;
};
