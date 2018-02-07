// Item-derived class for ammunition

#pragma once

#include "Item.h"
//#include <string>   // std::string

class Ammo :
    public Item
{
public:
    Ammo(std::string name, std::string description, int count, int stack,
         int value, double weight, std::string tags);
    ~Ammo();

    virtual void debugPrint() const override;
    virtual void setCount(int count) override;
    virtual int getCount() const override;
    virtual int getStack() const override;
    virtual std::string getTags() const override;

private:
    int m_count;
    int m_stack;
};

