// Static class for files management and utility

#pragma once

#include <fstream>  // std::fstream
#include <string>   // std::string

#define ITEMS "item_id.txt"
#define PERKS "perk_id.txt"

class File
{
public:
    ~File();

    static File * open(std::string file_type);
    bool findItem(std::string item_id);
    void setReadPosition();
    std::string getString();
    int getInt();
    double getDouble();
    void closeFile();

private:
    static File * m_instance;
    std::fstream m_working_file;

private:
    File(std::string file_type);
};
