#include "stdafx.h"
#include <iostream>
#include <string>
#include "Armor.h"

Armor::Armor(std::string name, std::string description, int reduction, int evasion, int protection, int value, double weight)
{
	this->name = name;
	this->description = description;
	this->reduction = reduction;
	this->evasion = evasion;
	this->protection = protection;
	this->value = value;
	this->weight = weight;
}

void Armor::debug_print() const
{
	std::cout << name << ": " << description << " DT: " << reduction << " EV: "
			  << evasion << " PROT: " << protection << " VAL: " << value
			  << " WG: " << weight << std::endl;
}

Armor::~Armor()
{
}
