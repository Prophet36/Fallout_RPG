#pragma once

#include "Character.h"
#include "Human.h"
#include <vector>

class Gameplay
{
public:
    /**
     * Copy constructor is inaccessible.
     */
    Gameplay(const Gameplay & rhs) = delete;

    /**
     * Assignment operator is inaccessible.
     */
    void operator=(const Gameplay & rhs) = delete;

    /**
     * Creates instance of Gameplay object if one isn't present, otherwise
     * returns pointer to existing instance.
     */
    static Gameplay * start();

    /**
     * Stops gameplay action and deletes instance of Gameplay object.
     */
    void stop();

    /**
     * Prompts the user to add new character into the game, asking him for
     * type and name of the character to be added.
     */
    void addCharacter();

    /**
     * Prompts the user to delete existing character, erasing it from the game.
     */
    void deleteCharacter();

    /**
     * Prints out list of existing characters (along with equipped items for
     * human characters).
     */
    void printCharacters();

    /**
     * Prompts the user to select existing character for further manipulation.
     */
    void selectCharacter();

    /**
     * Returns currently selected character for further manipulation.
     *
     * @return  pointer to Human object, representing currently selected
     *          character
     */
    Character * getCharacter() { return m_selected; }

private:
    /**
     * Class constructor. Creates instance of Gameplay object.
     */
    Gameplay();

    /**
     * Default class destructor. Deletes instance of Gameplay object and all
     * existing characters.
     */
    ~Gameplay();

private:
    /**
     * Pointer to instance of Gameplay object.
     */
    static Gameplay * m_instance;

    /**
     * Vector of pointers to Character objects. Stores pointers to all active
     * characters taking part in the game, representing players and game master
     * controlled characters.
     */
    std::vector<Character *> m_characters;

    /**
     * Pointer to Character object, representing currently selected character
     * for gameplay purposes.
     */
    Character * m_selected;
};

