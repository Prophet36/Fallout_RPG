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
               int magnitude, int duration, int count, int value, double weight,
               std::string tags);
    ~Consumable();

    virtual void debugPrint() const override;
    virtual void setCount(int count) override;
    virtual int getCount() const override;
    virtual std::string getTags() const override;

private:
    int m_attribute;
    int m_magnitude;
    int m_duration;
    int m_count;
};
