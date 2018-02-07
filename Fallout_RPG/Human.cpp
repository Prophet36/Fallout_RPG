#include "stdafx.h"
#include "Ammo.h"
#include "File.h"
#include "FItem.h"
#include "Human.h"
#include "Input.h"
#include "Inventory.h"
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
        Item * new_item = FItem::createNewItem(item_id);

        switch (Inventory::checkItemPrefix(item_id))
        {
            case Inventory::CONSUMABLE:
            case Inventory::AMMO:
            {
                sortInventory(new_item);
                break;
            }
            default:
            {
                inventory.push_back(new_item);
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

void Human::sortInventory(Item * new_item)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory.at(i)->getTags() == new_item->getTags())
        {
            int temp = inventory.at(i)->getStack() -
                       inventory.at(i)->getCount();
            if (temp >= new_item->getCount())
            {
                inventory.at(i)->setCount(inventory.at(i)->getCount() +
                                          new_item->getCount());
                delete new_item;
                new_item = nullptr;
                break;
            }
            else
            {
                inventory.at(i)->setCount(inventory.at(i)->getStack());
                new_item->setCount(new_item->getCount() - temp);
            }
        }
    }
    if (new_item)
        inventory.push_back(new_item);
}
