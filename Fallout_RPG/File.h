// Static class for files management and utility

#pragma once

#include <fstream>  // std::fstream
#include <string>   // std::string

#define ITEMS "item_id.txt"

class File
{
public:
    enum { ITEM_LIST };

public:
    static int findItem(std::string item_id);
    static std::fstream openFileAt(int position, std::string file_type);
    static void setReadPosition(std::fstream & working_file);
    static std::string getString(std::fstream & working_file);
    static int getInt(std::fstream & working_file);
    static double getDouble(std::fstream & working_file);
    static void closeFile(std::fstream & working_file);

private:
    File();
    ~File();

};
