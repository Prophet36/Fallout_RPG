#pragma once

#include "Character.h"
#include "Inventory.h"

/**
 * This class is for human character objects. It inherits from Character class,
 * particularly members and methods common to all characters in the game.
 *
 * This class contains additional members and methods specific to humanoid
 * characters.
 *
 * @author  Mateusz Warchol
 * @see     Character
 * @see     Inventory
 */
class Human :
    public Character
{
public:
    /**
     * Class constructor. Creates instance of Human object with specified
     * parameters.
     *
     * @param name          string containing character's name
     * @param level         value specifying character's level
     * @param strength      value specifying character's strength attribute
     * @param agility       value specifying character's agility attribute
     * @param vitality      value specifying character's vitality attribute
     * @param perception    value specifying character's perception attribute
     * @param intelligence  value specifying character's intelligence attribute
     * @param luck          value specifying character's luck attribute
     */
    Human(std::string name, int level = 1, int strength = 5, int agility = 5,
          int vitality = 5, int perception = 5, int intelligence = 5,
          int luck = 5);

    /**
    * Default class destructor. Deletes instance of Human object.
    */
    virtual ~Human() = default;

    /**
    * Assignment operator is inaccessible.
    */
    void operator=(const Human &) = delete;

    void print() const override;

protected:
    /**
     * Value specifying available skillpoints.
     */
    int m_skillpoints;
};
