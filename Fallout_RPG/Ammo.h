// Item-derived class for ammunition

#pragma once

#include "Item.h"
//#include <string>   // std::string

class Ammo :
    public Item
{
public:
    Ammo(std::string name, std::string description, int stack,
         int current_count, int value, double weight);
    ~Ammo();

    virtual void debugPrint() const override;

private:
    int m_stack;
    int m_current_count;
};

