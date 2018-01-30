// Base item class

#pragma once

#include <string>   // std::string

class Item
{
public:
    Item(std::string name, std::string description, int value, double weight);
    ~Item();

    virtual void debugPrint() const = 0;

protected:
    std::string m_name;
    std::string m_description;
    int m_value;
    double m_weight;
};
