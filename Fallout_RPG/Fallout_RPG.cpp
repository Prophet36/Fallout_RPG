#include "stdafx.h"
#include "Input.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <vld.h>


int main()
{
    Menu::main_menu();

    Input::keyContinue(true);

    return 0;
}
