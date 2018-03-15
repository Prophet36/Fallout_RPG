#include "stdafx.h"
#include "File.h"
#include "Inventory.h"
#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::fstream
#include <string>   // std::string, std::getline

File * File::m_instance = nullptr;

File::File()
{
    std::cout << "DEBUG: ----- File opened! -----\n";
}

File::~File()
{
    std::cout << "DEBUG: ----- File closed! -----\n";
}

File * File::get(std::string file_type)
{
    if (!m_instance)
        m_instance = new File();
    if (!m_instance->m_working_file.is_open())
        m_instance->open(file_type);
    return m_instance;
}

void File::setReadPosition()
{
    while (m_working_file.get() != ' ')
        continue;
    while (m_working_file.get() == ' ')
        continue;

    m_working_file.seekg((int)m_working_file.tellg() - 1);
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

void File::open(std::string file_type)
{
    if (!m_working_file.is_open())
    {
        m_working_file.open(file_type);
    }
}

void File::close()
{
    if (m_working_file.is_open())
    {
        m_working_file.close();
    }

    m_instance = nullptr;
    delete this;
}
