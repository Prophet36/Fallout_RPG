#include "stdafx.h"
#include "File.h"
#include "FItem.h"
#include "Human.h"
#include "Input.h"
#include "Inventory.h"
#include "IStackable.h"
#include <iostream> // std::cout
#include <string>   // std::string

Human::Human(int max_space) :
    m_max_space(max_space)
{
}

Human::~Human()
{
    while (!inventory.empty())
    {
        delete inventory.back();
        inventory.pop_back();
    }
}

void Human::showInventory() const
{
    for (int i = 0; i < inventory.size(); i++)
    {
        std::cout << i + 1 << ": ";
        inventory[i]->debugPrint();
    }
}

void Human::addItemPrompt(std::string item_id)
{
    if (File::open(ITEMS)->findItem(item_id))
    {
        Item * created_item = FItem::createNewItem(item_id);

        switch (Inventory::checkItemPrefix(item_id))
        {
            case Inventory::CONSUMABLE:
            case Inventory::AMMO:
            {
                sortInventory(created_item);
                break;
            }
            default:
            {
                inventory.push_back(created_item);
                break;
            }
        }
        while(checkInventoryEncumbrance())
        {
            Input::keyContinue();
            deleteItemPrompt();
        }
    }
    File::open(ITEMS)->closeFile();
}

void Human::deleteItemPrompt()
{
    if (inventory.size() != 0)
    {
        std::cout << "Which item would you like to delete?";
        Input::keyContinue();
        showInventory();
        std::cout << "Enter your choice: (0 to cancel): ";

        if(int choice = Input::switchPrompt(0, int(inventory.size())))
        { 
            delete inventory[choice - 1];
            inventory.erase(inventory.begin() + choice - 1);
        }
    }
    else
    {
        std::cout << "Your inventory is empty!";
        Input::keyContinue();
    }
}

bool Human::checkInventorySpace() const
{
    if (inventory.size() == m_max_space)
    {
        std::cout << "Warning: Your inventory is currently full!\n"
                     "Do you still want to add another item? (y/n): ";
        if (Input::yesNoPrompt() == 'y')
            return true;
        else
            return false;
    }
    return true;
}

bool Human::checkInventoryEncumbrance() const
{
    if (inventory.size() > m_max_space)
    {
        std::cout << "You are over encumbered!";
        return true;
    }
    return false;
}

void Human::sortInventory(Item * created_item)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getTags() == created_item->getTags())
        {
            IStackable * inv_item = dynamic_cast<IStackable *>(inventory[i]);
            IStackable * add_item = dynamic_cast<IStackable *>(created_item);
            if (inv_item && add_item)
            {
                add_item->setCount(inv_item->setCount(inv_item->getCount() +
                                                      add_item->getCount()));
                if (add_item->getCount() == 0)
                {
                    delete created_item;
                    created_item = nullptr;
                    break;
                }
            }
        }
    }
    if (created_item)
        inventory.push_back(created_item);
}
