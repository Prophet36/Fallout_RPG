#pragma once

#include "Human.h"

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
class Player : public Human
{
public:
    /**
     * Class constructor. Creates instance of Player object.
     */
    Player();

    /**
     * Class destructor. Deletes instance of Player object.
     */
    virtual ~Player();

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
