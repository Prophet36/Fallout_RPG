#pragma once

#include "Weapon.h"
#include <string>   // std::string

/**
 * This class is for melee weapon type objects. It inherits from Weapon class,
 * particularly members and methods common to all weapons in the game.
 *
 * This class contains description and statistics (attributes) describing melee
 * weapons. Its methods consist of printing those statistics as well as
 * returning particular attributes.
 *
 * @author  Mateusz Warchol
 * @see     Weapon
 */
class MeleeWeapon : public Weapon
{
public:
    /**
     * Class constructor. Creates instance of MeleeWeapon object with specified
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
    MeleeWeapon(std::string name, std::string description, int damage,
                std::string roll, int speed, int penetration, int requirement,
                int value, double weight, std::string tags);

    /**
     * Default class destructor. Deletes instance of MeleeWeapon object.
     */
    virtual ~MeleeWeapon() = default;

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;
};
