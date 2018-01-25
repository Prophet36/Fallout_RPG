#include "stdafx.h"
#include <iostream>	// std::cout
#include <string>	// std::string
#include "Consumable.h"


Consumable::Consumable(std::string name, std::string description, int attribute,
					   int magnitude, int duration, int value, double weight)
{
	this->name = name;
	this->description = description;
	this->attribute = attribute;
	this->magnitude = magnitude;
	this->duration = duration;
	this->value = value;
	this->weight = weight;
}

void Consumable::debug_print() const
{
	std::cout << name << ": " << description << " Gives " << magnitude << " "
			  << attribute << " for " << duration << " turns. VAL: " << value
			  << " WG: " << weight << std::endl;
}

Consumable::~Consumable()
{
}
