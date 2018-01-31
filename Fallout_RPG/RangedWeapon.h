// Weapon-derived class for ranged weapons

#pragma once

#include "Weapon.h"
#include <string>   // std::string

class RangedWeapon : public Weapon
{
public:
    RangedWeapon(std::string name, std::string description, int ammo_type,
                 int capacity, int damage, std::string roll, int speed,
                 int accuracy, int penetration, int requirement, int value,
                 double weight, std::string tags);
    ~RangedWeapon();

    virtual void debugPrint() const override;

private:
    int m_capacity;
    int m_current_ammo;
    int m_ammo_type;
    int m_accuracy;
};
