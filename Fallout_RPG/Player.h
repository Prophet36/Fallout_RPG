// Character-derived class for player human characters

#pragma once

#include "Human.h"

class Player : public Human
{
public:
	Player();
	~Player();
private:
	int m_experience;
};
