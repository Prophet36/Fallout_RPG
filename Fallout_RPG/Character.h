#pragma once

#include "Inventory.h"
#include <string>

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
     * Class constructor. Creates instance of Character object with specified
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
    Character(std::string name, int level = 1, int strength = 5,
              int agility = 5, int vitality = 5, int perception = 5,
              int intelligence = 5, int luck = 5);

    /**
     * Copy constructor is inaccessible.
     */
    Character(const Character &) = delete;

    /**
     * Class destructor. Deletes instance of Character object along with it's
     * inventory.
     */
    virtual ~Character();

    /**
     * Assignment operator is inaccessible.
     */
    void operator=(const Character &) = delete;

    /**
     * Prints the parameters of the object.
     */
    virtual void print() const = 0;

    /**
     * Returns character's name.
     *
     * @return  string containing character's name
     */
    std::string getName() const { return m_name; }

    /**
     * Returns character's level.
     *
     * @return  value containing character's level
     */
    int getLevel() const { return m_level; }
    
    /**
     * Returns character's strength attribute.
     *
     * @return  value containing character's strength
     */
    int getStrength() const { return m_strength; }

    /**
     * Returns character's agility attribute.
     *
     * @return  value containing character's agility
     */
    int getAgility() const { return m_agility; }

    /**
     * Returns character's vitality attribute.
     *
     * @return  value containing character's vitality
     */
    int getVitality() const { return m_vitality; }

    /**
     * Returns character's perception attribute
     *
     * @return  value containing character's perception
     */
    int getPerception() const { return m_perception; }

    /**
     * Returns character's intelligence attribute.
     *
     * @return  value containing character's intelligence
     */
    int getIntelligence() const { return m_intelligence; }

    /**
     * Returns character's luck attribute.
     *
     * @return  value containing character's luck
     */
    int getLuck() const { return m_luck; }

    /**
     * Returns character's current health.
     *
     * @return  value containing character's current health
     */
    int getHealth() const { return m_health; }

    /**
     * Returns additional melee damage the character does in combat.
     *
     * @return  value containing bonus to melee damage, based on character's
     *          strength (characters with strength of 5 or less don't get bonus
     *          to melee damage)
    */
    int getMeleeBonus() const { return (m_strength > 5 ? m_strength - 5 : 0); }

    /**
     * Returns character's maximum weight the character can carry.
     *
     * @return  value containing character's weight limit, based on strength
     */
    int getMaxWeight() const { return 20 + m_strength * 2; }

    /**
     * Returns bonus (or malus) to character's speed in combat (turn order).
     * This bonus stacks with equipped weapon's speed.
     *
     * @return  value containing bonus (if agility is higher than 5) or malus
     *          (if less than 5) to speed in combat
     */
    int getSpeedBonus() const { return m_agility - 5; }

    /**
     * Returns bonus to character's evasion of incoming attacks. This bonus
     * stacks with equipped armor's evasion.
     *
     * @return  value containing bonus to evasion, based on character's agility
     *          (characters with agility of 5 or less don't get bonus to
     *          evasion)
     */
    int getEvasionBonus() const { return (m_agility > 5 ? m_agility - 5 : 0); }

    /**
     * Returns character's maximum health.
     *
     * @return  value containing character's maximum health, based on vitality
     */
    int getMaxHealth() const { return 12 + m_vitality * 2 + m_level * 2; }

    /**
     * Returns bonus (or malus) to protection from radiation. This bonus stacks
     * with equipped armor's protection.
     *
     * @return  value containing bonus (if endurance is higher than 5) or malus
     *          (if less than 5) to protection from radiation, measured in %
     */
    int getProtectionBonus() const { return -25 + m_vitality * 5; }

    /**
     * Returns character's protection from poisoning.
     *
     * @return  value containing bonus to protection from poisoning, based on
     *          vitality
     */
    int getPoisonBonus() const { return m_vitality * 5; }

    /**
     * Returns character's bonus to accuracy with attacks.
     *
     * @return  value containing character's bonus to accuracy
     */
    int getAimBonus() const { return m_perception; }

    /**
     * Returns character's bonus to roll, when fate is involved.
     *
     * @return  value containing character's bonus to roll, based on luck
     */
    int getFateBonus() const { return m_luck; }

    /**
     * Returns character's bonus to finding additional loot.
     *
     * @return  value containing bonus to finding additional, or better, loot,
     *          based on luck
     */
    int getLootBonus() const { return m_luck * 5; }

    /**
     * Returns character's inventory, for further manipulation.
     *
     * @return  pointer to Inventory object, containing character's current
     *          inventory
     */
    Inventory * getInventory() const { return m_inventory; }

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
     * Value specifying character's current health.
     */
    int m_health;

    /**
     * Contains character's inventory, represented as pointer to Inventory class
     * object.
     */
    Inventory * m_inventory;
};
