// Item-derived class for armor

#pragma once

#include "Item.h"

class Armor : public Item
{
public:
    Armor(std::string name, std::string description, int reduction, int evasion,
          int protection, int value, double weight);
    ~Armor();

    virtual void debugPrint() const override;

private:
    int m_reduction;
    int m_evasion;
    int m_protection;
};
