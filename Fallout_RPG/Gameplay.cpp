#include "stdafx.h"
#include "Critter.h"
#include "Gameplay.h"
#include "Human.h"
#include "Input.h"
#include "Player.h"
#include <iostream>

Gameplay * Gameplay::m_instance = nullptr;

Gameplay::Gameplay()
{
    m_selected = nullptr;
}

Gameplay::~Gameplay()
{
    while (!m_characters.empty())
    {
        delete m_characters.back();
        m_characters.pop_back();
    }
}

Gameplay * Gameplay::start()
{
    if (!m_instance)
    {
        m_instance = new Gameplay();
        std::cout << "DEBUG: ----- Gameplay started! -----\n";
    }
    return m_instance;
}

void Gameplay::stop()
{
    if (m_instance)
    {
        m_instance = nullptr;
        delete this;
    }
}

void Gameplay::addCharacter()
{
    std::cout << "What type of character to add? (0 - cancel)\n"
                 "1 - player\n"
                 "2 - enemy\n"
                 "3 - critter\n";
    switch (Input::switchPrompt(1, 3))
    {
        case 1:
        {
            std::cout << "Enter player's name: ";
            m_characters.push_back(new Player(Input::getString()));
            break;
        }
        case 2:
        {
            std::cout << "Enter character's name: ";
            m_characters.push_back(new Human(Input::getString()));
            break;
        }
        case 3:
        {
            m_characters.push_back(new Critter("Dog", 1, 2, 3, 4, 5, 4, 3, 10,
                                               0, "weapon_dogbite", 10, "dog"));
            break;
        }
        default:
        {
            std::cout << "Exiting...\n";
            break;
        }
    }
}

void Gameplay::deleteCharacter()
{
    if (m_characters.size() != 0)
    {
        std::cout << "Which character would you like to delete?";
        Input::keyContinue();
        printCharacters();
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, int(m_characters.size())))
        {
            delete m_characters[choice - 1];
            m_characters.erase(m_characters.begin() + choice - 1);
        }
    }
    else
    {
        std::cout << "There are no characters in the game!";
        Input::keyContinue();
    }
}

void Gameplay::printCharacters()
{
    if (!m_characters.empty())
    {
        for (unsigned int i = 0; i < m_characters.size(); i++)
        {
            std::cout << i + 1 << ": ";
            m_characters[i]->print();
        }
    }
    else
    {
        std::cout << "There are no characters in the game!";
        Input::keyContinue();
    }
}

void Gameplay::selectCharacter()
{
    if (!m_characters.empty())
    {
        std::cout << "Which character would you like to modify?";
        Input::keyContinue();
        printCharacters();
        std::cout << "Enter your choice: (0 to cancel): ";

        if (int choice = Input::switchPrompt(0, int(m_characters.size())))
            m_selected = m_characters[choice - 1];
        else
            m_selected = nullptr;
    }
    else
    {
        std::cout << "There are no characters in the game!";
        Input::keyContinue();
    }
}
