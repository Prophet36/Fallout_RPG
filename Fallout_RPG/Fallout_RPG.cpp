// Fallout_RPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Item.h"
#include "Consumable.h"

int main()
{
	int type;
	Item * ptr = nullptr;

	do
	{
		std::cout << "DEBUG: What item to give? ";
		std::cin >> type;

		ptr = new Consumable(type);
		ptr->debug_print();
		delete ptr;

	} while (type >= 0);

    return 0;
}
