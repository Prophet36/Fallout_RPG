#include "stdafx.h"
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
    if (checkInventorySpace())
    {
        if (File::open()->findItem(item_id))
        {
            inventory.push_back(FItem::createNewItem(item_id));
        }
        File::open()->closeFile();
    }
}

void Human::deleteItemPrompt()
{
    if (inventory.size() != 0)
    {
        std::cout << "Which item would you like to delete?\n";
        showInventory();

        int choice = Input::switchPrompt(1, int(inventory.size()));
        delete inventory[choice - 1];
        inventory.erase(inventory.begin() + choice - 1);
    }
    else
    {
        std::cout << "Your inventory is empty!\n";
    }
}

bool Human::checkInventorySpace(bool adding_item) const
{
    if (inventory.size() >= m_max_space)
    {
        if (adding_item)
        {
            std::cout << "You have full inventory!\n";
        }
        return false;
    }
    else
    {
        return true;
    }
}

Human::~Human()
{
    while (!inventory.empty())
    {
        delete inventory.back();
        inventory.pop_back();
    }
}
