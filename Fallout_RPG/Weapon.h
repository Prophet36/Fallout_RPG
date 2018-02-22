// Item-derived class for weapons

#pragma once

#include <string>   // std::string
#include "Item.h"

class Weapon : public Item
{
public:
    Weapon(std::string name, std::string description, int damage,
           std::string roll, int speed, int penetration, int requirement,
           int value, double weight, std::string tags);
    ~Weapon();

    virtual void debugPrint() const = 0;
    virtual std::string getTags() const = 0;
    int getMinDamage() const;
    int getMaxDamage() const;

protected:
    std::string m_roll;
    int m_damage;
    int m_speed;
    int m_penetration;
    int m_requirement;
};
