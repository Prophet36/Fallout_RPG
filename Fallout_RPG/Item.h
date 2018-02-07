// Base item class

#pragma once

#include <string>   // std::string

class Item
{
public:
    Item(std::string name, std::string description, int value, double weight,
         std::string tags);
    ~Item();

    virtual void debugPrint() const = 0;
    virtual void setCount(int count) = 0;
    virtual int getCount() const = 0;
    virtual int getStack() const = 0;
    virtual std::string getTags() const = 0;

protected:
    std::string m_name;
    std::string m_description;
    std::string m_tags;
    int m_value;
    double m_weight;
};
