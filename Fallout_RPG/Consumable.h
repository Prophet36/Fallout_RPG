// Item-derived class for consumable items

#pragma once

#include "Item.h"

class Consumable : public Item
{
public:
    enum { STRENGTH, ENDURANCE, AGILITY, PERCEPTION, INTELLIGENCE, LUCK, HEALTH,
           RADS };

public:
    Consumable(std::string name, std::string description, int attribute,
               int magnitude, int duration, int value, double weight);
    ~Consumable();

    virtual void debugPrint() const override;

private:
    int m_attribute;
    int m_magnitude;
    int m_duration;
};
