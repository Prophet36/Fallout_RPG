#pragma once

#include "Human.h"
#include <string>

/**
 * This class for player controlled character objects. It inherits from Human
 * class, particularly members and methods common to all humanoid characters in
 * the game.
 *
 * This class contains additional members and methods specific to player
 * controlled characters.
 *
 * @author  Mateusz Warchol
 * @see     Human
 */
class Player :
    public Human
{
public:
    /**
     * Class constructor. Creates instance of Player object with specified
     * parameters.
     *
     * @param name          string containing player's name
     * @param level         value specifying player's level
     * @param strength      value specifying player's strength attribute
     * @param agility       value specifying player's agility attribute
     * @param vitality      value specifying player's vitality attribute
     * @param perception    value specifying player's perception attribute
     * @param intelligence  value specifying player's intelligence attribute
     * @param luck          value specifying player's luck attribute
     */
    Player(std::string name, int level = 1, int strength = 5, int agility = 5,
           int vitality = 5, int perception = 5, int intelligence = 5,
           int luck = 5);

    /**
     * Default class destructor. Deletes instance of Player object.
     */
    virtual ~Player() = default;

    /**
     * Returns player's available skillpoints.
     *
     * @return  value specifying player's available skillpoints.
     */
    int getSkillpoints() const { return m_skillpoints; }

    /**
     * Returns player's current experience points.
     *
     * @return  value specifying player's experience points
     */
    int getExperience() const { return m_experience; }

private:
    /**
     * Value specifying current experience points.
     */
    int m_experience;
};
