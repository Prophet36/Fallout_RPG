#include "stdafx.h"
#include "File.h"
#include "Inventory.h"
#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::fstream
#include <string>   // std::string, std::getline
#include <vector>   // std::vector

File * File::m_instance = nullptr;

File::File()
{
    m_working_file.open(ITEMS);
    std::cout << "DEBUG: ----- File opened! -----\n";
}

File * File::open()
{
    if (!m_instance)
        m_instance = new File();
    return m_instance;
}

bool File::findItem(std::string item_id)
{
    std::string buffer;

    if (m_working_file.is_open())
    {
        if (Inventory::checkItemPrefix(item_id) != -1)
        {
            while ((m_working_file >> buffer))
            {
                if (buffer == item_id)
                    return true;
            }
        }
        std::cerr << "ERROR: Incorrect item!\n";
    }
    else
    {
        std::cerr << "ERROR: Can't open file!\n";
    }
    return false;
}

//std::fstream File::openFileAt(int position, std::string file_type)
//{
//    std::fstream working_file(file_type);
//    working_file.seekg(position);
//    return working_file;
//}

void File::setReadPosition()
{
    while (m_working_file.get() != ' ')
        continue;
    while (m_working_file.get() == ' ')
        continue;

    m_working_file.seekg((int)m_working_file.tellg() - 1);
}

std::string File::getString()
{
    setReadPosition();
    std::string temp;
    std::getline(m_working_file, temp);
    return temp;
}

int File::getInt()
{
    setReadPosition();
    int temp;
    m_working_file >> temp;
    return temp;
}

double File::getDouble()
{
    setReadPosition();
    double temp;
    m_working_file >> temp;
    return temp;
}

void File::closeFile()
{
    if (m_working_file.is_open())
    {
        m_working_file.close();
        delete m_instance;
        m_instance = nullptr;
    }
}

File::~File()
{
    std::cout << "DEBUG: ----- File closed! -----\n";
}
