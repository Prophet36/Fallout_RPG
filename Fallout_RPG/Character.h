// Base character class

#pragma once

#include <string>

class Character
{
public:
	Character();
	~Character();

protected:
	const std::string m_name;
	int m_level;
	int m_strength;
	int m_agility;
	int m_vitality;
	int m_perception;
	int m_intelligence;
	int m_luck;
	int m_health_max;
	int m_health_current;
};

