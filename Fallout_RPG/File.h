#pragma once

#include <fstream>  // std::fstream
#include <string>   // std::string

/**
 * Global strings containing names of files attached to the game.
 *
 * item_id.txt holds information about all existing items, with all their
 * parameters.
 * perk_id.txt holds information about all existing perks for characters, with
 * all their parameters.
 * critter_id.txt holds information about all existing critter type characters
 * (non-humanoid enemies, like mutants, dogs, etc), with all their parameters.
 */
const std::string c_items = "item_id.txt";
const std::string c_perks = "perk_id.txt";
const std::string c_critters = "critter_id.txt";

/**
 * This class is for file management, namely opening, closing and reading from
 * files. There can be only one instance of this class (and one file open).
 *
 * Methods of this class consist of opening, closing, and getting particular
 * data from attached files.
 *
 * @author  Mateusz Warchol
 */
class File
{
public:
    /**
     * Copy constructor is inaccessible.
     */
    File(const File & rhs) = delete;

    /**
     * Assignment operator is inaccessible.
     */
    void operator=(const File & rhs) = delete;

    /**
     * Creates instance of File object if one isn't present and open specified
     * file, otherwise returns pointer to existing instance. Calls open();
     *
     * @return  pointer to instance of File object
     */
    static File * get(std::string file_type);

    /**
     * Closes file if currently opened and deletes instance of File object.
     */
    void close();

    /**
     * Finds specified item in the opened file by checking against matching
     * item ID. If found, leaves cursor after item ID parameter, otherwise
     * leaves cursor at the end of the file.
     *
     * @param item_id   ID of the item to find
     * @return          true if specified item is found, otherwise false
     */
    bool findItem(std::string item_id);

    /**
     * Returns next parameter of the item as string.
     *
     * @return  string containing item's parameter from file
     */
    std::string getString();

    /**
     * Returns next parameter of the item as integer.
     *
     * @return  value containing item's parameter from file
     */
    int getInt();

    /**
     * Returns next parameter of the item as double.
     *
     * @return  double value containing item's parameter from file
     */
    double getDouble();

private:
    /**
     * Default class constructor. Creates instance of File object.
     */
    File() = default;

    /**
     * Default class destructor. Deletes instance of File object.
     */
    ~File() = default;

    /**
     * Opens specified file, if no files are opened.
     *
     * @param file_type string containing name of the file to open
     */
    void open(std::string file_type);

    /**
     * Sets cursor position within file to read next parameter of the item.
     */
    void setReadPosition();

private:
    /**
     * Pointer to instance of File object.
     */
    static File * m_instance;

    /**
     * File that is being opened and worked, read from.
     */
    std::fstream m_working_file;
};
