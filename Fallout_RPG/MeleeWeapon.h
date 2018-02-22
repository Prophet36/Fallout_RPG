// Weapon-derived class for melee weapons

#pragma once

#include "Weapon.h"
#include <string>   // std::string

class MeleeWeapon : public Weapon
{
public:
    MeleeWeapon(std::string name, std::string description, int damage,
                std::string roll, int speed, int penetration, int requirement,
                int value, double weight, std::string tags);
    ~MeleeWeapon();

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const override;
};
