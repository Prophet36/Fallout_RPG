// Base item class

#pragma once

#include <string>   // std::string

class Item
{
public:
    Item(std::string name, std::string description, int value, double weight,
         std::string tags);
    virtual ~Item();

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const = 0;

    /**
     * Returns the object's tags field.
     *
     * @return  string containing tags associated with the object
     */
    std::string getTags() const;

protected:
    std::string m_name;
    std::string m_description;
    std::string m_tags;
    int m_value;
    double m_weight;
};
