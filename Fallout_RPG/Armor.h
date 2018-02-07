// Item-derived class for armor

#pragma once

#include "Item.h"

class Armor : public Item
{
public:
    Armor(std::string name, std::string description, int reduction, int evasion,
          int protection, int value, double weight, std::string tags);
    ~Armor();

    virtual void debugPrint() const override;
    virtual void setCount(int count) override;
    virtual int getCount() const override;
    virtual std::string getTags() const override;

private:
    int m_reduction;
    int m_evasion;
    int m_protection;
};
