#pragma once

#include <string>   // std::string

/**
 * This is base class for all items in the game. It contains members and methods
 * that are common to every item type. Classes for specific item types are
 * derived from this class and implement their own members and methods, which
 * are specific to those classes.
 *
 * @author  Mateusz Warchol
 * @see     Ammo
 * @see     Armor
 * @see     Consumable
 * @see     Weapon
 */
class Item
{
public:
    /**
     * Class constructor. Creates instance of Item object with specified
     * parameters.
     *
     * @param name          string containing name of the object
     * @param description   string containing description of the object
     * @param value         monetary value of this object
     * @param weight        double value containing the object's weight
     * @param tags          string containing tags associated with this object
     */
    Item(std::string name, std::string description, int value, double weight,
         std::string tags);

    /**
     * Class desctructor. Deletes instance of Item object.
     */
    virtual ~Item();

    /**
     * Prints the parameters of the object for debug purposes.
     */
    virtual void debugPrint() const = 0;

    /**
     * Returns the object's name.
     *
     * @return  string containing name of the object
     */
    std::string getName() const { return m_name; }

    /**
     * Returns the object's description.
     *
     * @return  string containing short description of the object
     */
    std::string getDescription() const { return m_description; }

    /**
     * Returns the object's tags field.
     *
     * @return  string containing tags associated with the object
     */
    std::string getTags() const { return m_tags; }

    /**
     * Returns the object's value.
     *
     * @return  monetary value of the object
     */
    int getValue() const { return m_value; }

    /**
     * Returns the object's weight.
     *
     * @return  double containing weight of the object
     */
     double getWeight() const { return m_weight; }

protected:
    /**
     * This is the name of the item.
     */
    std::string m_name;

    /**
     * Short description of the item.
     */
    std::string m_description;

    /**
     * Contains tags associated with the item. Each tag is separated by a comma.
     */
    std::string m_tags;

    /**
     * Monetary value of the item.
     */
    int m_value;

    /**
     * Weight of the item, measured in game units.
     */
    double m_weight;
};
