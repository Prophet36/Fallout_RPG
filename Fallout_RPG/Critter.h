#pragma once

#include "Character.h"
#include "MeleeWeapon.h"
#include <string>

class Critter :
    public Character
{
public:

    Critter(std::string name, int level, int strength, int agility,
            int vitality, int perception, int intelligence, int luck,
            int health_bonus, std::string attack, int reduction, int experience,
            std::string type);

    virtual ~Critter() = default;

    void print() const override;

private:
    std::string m_type;
    int m_health_bonus;
    int m_reduction;
    int m_experience;
};

