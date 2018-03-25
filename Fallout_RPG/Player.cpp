#include "stdafx.h"
#include "Player.h"
#include <iostream>

Player::Player(std::string name, int level, int strength, int agility,
               int vitality, int perception, int intelligence, int luck) :
    Human(name, level, strength, agility, vitality, perception, intelligence,
          luck)
{
}
