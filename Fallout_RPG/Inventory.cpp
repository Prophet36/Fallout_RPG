#include "stdafx.h"
#include "File.h"
#include "FItem.h"
#include "Input.h"
#include "Inventory.h"
#include "IStackable.h"
#include "Item.h"
#include <iostream> // std::cout
#include <string>   // std::string
#include <vector>   // std::vector


Inventory::Inventory(int max_space) :
    m_max_space(max_space)
{
}

Inventory::~Inventory()
{
    while (!m_items.empty())
    {
        delete m_items.back();
        m_items.pop_back();
    }
}

int Inventory::checkItemPrefix(std::string item_id)
{
    std::string prefixes[] = { "item_", "weapon_", "ammo_", "armor_" };

    for (int i = 0; i < (sizeof(prefixes) / sizeof(prefixes[0])); i++)
    {
        if (item_id.find(prefixes[i], 0) != std::string::npos)
        {
            return i;
        }
    }

    return -1;
}

int Inventory::checkConsumableBonus(std::string bonus)
{
    std::string bonuses[] = { "STRENGTH", "ENDURANCE", "AGILITY", "PERCEPTION",
                              "INTELLIGENCE", "LUCK", "HEALTH", "RADS" };

    for (int i = 0; i < (sizeof(bonuses) / sizeof(bonuses[0])); i++)
    {
        if (bonus.find(bonuses[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}

int Inventory::checkWeaponType(std::string tags)
{
    std::string types[] = { "melee", "ranged" };

    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++)
    {
        if (tags.find(types[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}
int Inventory::checkAmmoType(std::string tags)
{
    std::string types[] = { "9mm", "45 ACP", ".357", ".44", "20ga", "12ga",
                            "5.56mm", ".308", "50 BMG", "EC" };

    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++)
    {
        if (tags.find(types[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}

void Inventory::print() const
{
    if (!m_items.empty())
    {
        for (int i = 0; i < m_items.size(); i++)
        {
            std::cout << i + 1 << ": ";
            m_items[i]->debugPrint();
        }
    }
    else
    {
        std::cout << "Your inventory is empty!";
        Input::keyContinue();
    }
}

void Inventory::add(std::string item_id)
{
    if (File::get(c_items)->findItem(item_id))
    {
        Item * created_item = FItem::createNewItem(item_id);

        switch (Inventory::checkItemPrefix(item_id))
        {
            case Inventory::CONSUMABLE:
            case Inventory::AMMO:
            {
                sort(created_item);
                break;
            }
            default:
            {
                m_items.push_back(created_item);
                break;
            }
        }
        while (checkEncumbrance())
        {
            Input::keyContinue();
            remove();
        }
    }
    File::get(c_items)->close();
}

void Inventory::remove()
{
    if (m_items.size() != 0)
    {
        std::cout << "Which item would you like to delete?";
        Input::keyContinue();
        print();
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, int(m_items.size())))
        {
            delete m_items[choice - 1];
            m_items.erase(m_items.begin() + choice - 1);
        }
    }
    else
    {
        std::cout << "Your inventory is empty!";
        Input::keyContinue();
    }
}

bool Inventory::warnEncumbrance() const
{
    if (m_items.size() == m_max_space)
    {
        std::cout << "Warning: Your inventory is currently full!\n"
                     "Do you still want to add another item? (y/n): ";
        if (Input::yesNoPrompt())
            return true;
        else
            return false;
    }
    return true;
}

bool Inventory::checkEncumbrance() const
{
    if (m_items.size() > m_max_space)
    {
        std::cout << "You are over encumbered!";
        return true;
    }
    return false;
}

void Inventory::sort(Item * created_item)
{
    for (int i = 0; i < m_items.size(); i++)
    {
        if (m_items[i]->getTags() == created_item->getTags())
        {
            IStackable * inv_item = dynamic_cast<IStackable *>(m_items[i]);
            IStackable * added_item = dynamic_cast<IStackable *>(created_item);
            if (inv_item && added_item)
            {
                added_item->setCount(inv_item->setCount(inv_item->getCount() +
                            added_item->getCount()));
                if (added_item->getCount() == 0)
                {
                    delete created_item;
                    created_item = nullptr;
                    break;
                }
            }
        }
    }
    if (created_item)
        m_items.push_back(created_item);
}
