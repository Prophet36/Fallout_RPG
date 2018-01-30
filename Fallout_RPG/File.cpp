#include "stdafx.h"
#include "File.h"
#include "Inventory.h"
#include <iostream> // std::cout
#include <fstream>  // std::fstream
#include <string>   // std::string, std::getline

File::File()
{
}

int File::findItem(std::string item_id)
{
    std::string buffer_s;

    std::fstream file_items(ITEMS);
    if (file_items.is_open())
    {
        if (Inventory::checkItemPrefix(item_id) != -1)
        {
            while ((file_items >> buffer_s))
            {
                if (buffer_s == item_id)
                {
                    int temp = (int)file_items.tellg();
                    file_items.close();
                    return temp;
                }
            }
        }
        std::cout << "ERROR: Incorrect item!\n";
    }
    else
    {
        std::cout << "ERROR: Can't open file!\n";
    }
    file_items.close();
    return 0;
}

std::fstream File::openFileAt(int position, std::string file_type)
{
    std::fstream working_file(file_type);
    working_file.seekg(position);
    return working_file;
}

void File::setReadPosition(std::fstream & working_file)
{
    while (working_file.get() != ' ')
        continue;
    while (working_file.get() == ' ')
        continue;

    working_file.seekg((int)working_file.tellg() - 1);
}

std::string File::getString(std::fstream & working_file)
{
    setReadPosition(working_file);
    std::string temp;
    std::getline(working_file, temp);
    return temp;
}

int File::getInt(std::fstream & working_file)
{
    setReadPosition(working_file);
    int temp;
    working_file >> temp;
    return temp;
}

double File::getDouble(std::fstream & working_file)
{
    setReadPosition(working_file);
    double temp;
    working_file >> temp;
    return temp;
}

void File::closeFile(std::fstream & working_file)
{
    if (working_file.is_open())
    {
        std::cout << "DEBUG: ----- File was opened, closing it now! -----\n";
        working_file.close();
    }
}

File::~File()
{
}
