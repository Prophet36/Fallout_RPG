#pragma once

#include <string>   // std::string

/**
 * This is base class for all character objects in the game. It contains members
 * and methods that are common to all characters in the game. Classes for
 * specific types of characters are derived from this class and implement
 * additional members and methods specific for those classes.
 *
 * @author  Mateusz Warchol
 */
class Character
{
public:
    /**
     * Class constructor. Creates instance of Character object.
     */
    Character();

    /**
     * Default class destructor. Deletes instance of Character object.
     */
    virtual ~Character() = default;

protected:
    /**
     * String containing name of the character.
     */
    std::string m_name;

    /**
     * Value specifying character's level.
     */
    int m_level;

    /**
     * Value specifying character's strength attribute.
     */
    int m_strength;

    /**
     * Value specifying character's agility attribute.
     */
    int m_agility;

    /**
     * Value specifying character's vitality attribute.
     */
    int m_vitality;

    /**
     * Value specifying character's perception attribute.
     */
    int m_perception;

    /**
     * Value specifying character's intelligence attribute.
     */
    int m_intelligence;

    /**
     * Value specifying character's luck attribute.
     */
    int m_luck;

    /**
     * Value specifying character's maximum health.
     */
    int m_health_max;

    /**
     * Value specifying character's current health.
     */
    int m_health_current;
};
