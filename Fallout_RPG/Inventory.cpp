#include "stdafx.h"
#include "Ammo.h"
#include "File.h"
#include "FItem.h"
#include "Input.h"
#include "Inventory.h"
#include "IStackable.h"
#include "Item.h"
#include "RangedWeapon.h"
#include <iostream> // std::cout
#include <string>   // std::string
#include <vector>   // std::vector


Inventory::Inventory(int max_space) :
    m_max_space(max_space), m_armor(nullptr), m_weapon(nullptr)
{
    add("weapon_fists");
    add("armor_nothing");
    m_weapon = m_items[0];
    m_armor = m_items[1];
    m_items.clear();
}

Inventory::~Inventory()
{
    while (!m_items.empty())
    {
        delete m_items.back();
        m_items.pop_back();
    }
    delete m_weapon;
    delete m_armor;
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

void Inventory::print(bool equipped) const
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
    if (equipped)
        printEquipped(int(m_items.size()) + 1);
}

void Inventory::add(std::string item_id, bool ignore_limit)
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
        while (!ignore_limit && checkEncumbrance())
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

void Inventory::equip()
{
    if (!m_items.empty())
    {
        std::cout << "Which item would you like to equip?";
        Input::keyContinue();
        print();
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, int(m_items.size())))
        {
            equip(choice - 1);
        }
    }
    else
    {
        std::cout << "Your inventory is empty!";
        Input::keyContinue();
    }
}

void Inventory::unequip()
{
    if (m_weapon->getName() == "Unarmed" && m_armor->getName() == "Underwear")
    {
        std::cout << "You don't have anything to unequip!\n";
    }
    else
    {
        std::cout << "Which item would you like to unequip?";
        Input::keyContinue();
        printEquipped();
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, 2))
        {
            unequip(choice);
        }
    }
}

void Inventory::reloadWeapon()
{
    if (m_items.size() != 0)
    {
        std::cout << "Which weapon would you like to reload?";
        Input::keyContinue();
        print(true);
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, int(m_items.size() + 1)))
        {
            reloadWeapon(choice - 1);
        }
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

void Inventory::sort(Item * created_item)
{
    for (int i = 0; i < m_items.size(); i++)
    {
        if (m_items[i]->getTags() == created_item->getTags())
        {
            IStackable * added_item = dynamic_cast<IStackable *>(created_item);
            IStackable * inv_item = dynamic_cast<IStackable *>(m_items[i]);
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

void Inventory::printEquipped(int list_start) const
{
    std::cout << list_start << ": WEAPON: ";
    m_weapon->debugPrint();
    std::cout << list_start + 1 << ": ARMOR: ";
    m_armor->debugPrint();
}

void Inventory::equip(int slot)
{
    switch (checkItemType(m_items[slot]->getTags()))
    {
        case WEAPON:
        {
            equipWeapon(slot);
            break;
        }
        case ARMOR:
        {
            equipArmor(slot);
            break;
        }
        default:
        {
            std::cout << "You can't equip this item!\n";
            break;
        }
    }
}

void Inventory::equipWeapon(int slot)
{
    std::cout << "Equipping " << m_items[slot]->getName() << std::endl;

    if (m_weapon->getName() == "Unarmed")
    {
        delete m_weapon;
        m_weapon = m_items[slot];
        m_items.erase(m_items.begin() + slot);
    }
    else
    {
        Item * temp = m_weapon;
        m_weapon = m_items[slot];
        m_items[slot] = temp;
    }
}

void Inventory::equipArmor(int slot)
{
    std::cout << "Equipping " << m_items[slot]->getName() << std::endl;

    if (m_armor->getName() == "Underwear")
    {
        delete m_armor;
        m_armor = m_items[slot];
        m_items.erase(m_items.begin() + slot);
    }
    else
    {
        Item * temp = m_armor;
        m_armor = m_items[slot];
        m_items[slot] = temp;
    }
}

void Inventory::unequip(int slot)
{
    switch (slot)
    {
        case 1:
        {
            if (m_weapon->getName() != "Unarmed")
            {
                std::cout << "Unquipping " << m_weapon->getName()
                          << std::endl;

                add("weapon_fists", true);
                equip(int(m_items.size()) - 1);
            }
            else
            {
                std::cout << "You can't unequip this!\n";
            }
            break;
        }
        case 2:
        {
            if (m_armor->getName() != "Underwear")
            {
                std::cout << "Unquipping " << m_armor->getName()
                          << std::endl;

                add("armor_nothing", true);
                equip(int(m_items.size()) - 1);
            }
            else
            {
                std::cout << "You can't unequip this!\n";
            }
            break;
        }
        default:
        {
            std::cerr << "ERROR: Incorrect slot!\n";
        }
    }

    while (checkEncumbrance())
    {
        Input::keyContinue();
        remove();
    }
}

void Inventory::reloadWeapon(int slot)
{
    bool success = false;
    RangedWeapon * reloaded = nullptr;

    if (slot == m_items.size())
        reloaded = dynamic_cast<RangedWeapon *>(m_weapon);
    else
        reloaded = dynamic_cast<RangedWeapon *>(m_items[slot]);

    if (reloaded)
    {
        if (reloaded->getCurrentAmmo() == reloaded->getCapacity())
        {
            std::cout << "This weapon is already full!\n";
        }
        else
        {
            std::string type = reloaded->getAmmoType();

            for (int i = 0; i < m_items.size(); i++)
            {
                if (m_items[i]->getTags().find(type) != std::string::npos)
                {
                    reloadWeapon(reloaded, i);
                    success = true;
                    break;
                }
            }
            if (!success)
            {
                std::cout << "You don't have available ammo for this weapon!\n";
            }
        }
    }
    else
    {
        std::cout << "You can't reload this item!\n";
    }
}

void Inventory::reloadWeapon(RangedWeapon * weapon, int slot)
{
    Ammo * ammunition = dynamic_cast<Ammo *>(m_items[slot]);

    if (ammunition)
    {
        m_items.erase(m_items.begin() + slot);

        int shortage = weapon->getCapacity() - weapon->getCurrentAmmo();

        if (ammunition->getCount() > shortage)
        {
            ammunition->setCount(ammunition->getCount() - shortage);
            weapon->setCurrentAmmo(weapon->getCapacity());
            sort(ammunition);
        }
        else if (ammunition->getCount() == shortage)
        {
            weapon->setCurrentAmmo(weapon->getCapacity());
            delete ammunition;
        }
        else
        {
            weapon->setCurrentAmmo(weapon->getCurrentAmmo() +
                                   ammunition->getCount());
            delete ammunition;
        }
        std::cout << "Reloaded " << weapon->getName() << ", now has "
                  << weapon->getCurrentAmmo() << " rounds\n";
    }
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

int Inventory::checkItemType(std::string tags)
{
    std::string types[] = { "item", "weapon", "ammo", "armor" };

    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++)
    {
        if (tags.find(types[i], 0) != std::string::npos)
        {
            return i;
        }
    }
    return -1;
}
