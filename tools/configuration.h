#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include <exception>
#include "macro.h"
#include "baseclass.h"

class Configuration : public BaseClass {

public:

    /* CONSTRUCTORS & DESTRUCTORS */


    /**
     * @brief configuration::configuration Default constructor
     *        Opens file named config.txt
     *        Saves local variables (Name & Location)
     */
    Configuration();


    /**
     * @brief configuration Constructor that takes the name of file and location of file
     * @param name std::string name of file
     * @param location std::string location of file
     */
    Configuration(std::string location, std::string name);


    /**
     * @brief ~configuration Look through each name/key
     *                       pair in the map and add them to the file
     */
    ~Configuration();


    /* READING AND STORING TO FILES */

    /**
     * @brief read_in: Read in information from a file
     *                 and put it into a map with a (key, value) pair.
     */
    void read_in(); // read in a file line by line


    /**
     * @brief store_to_file: Stores info from the hash map back to the file.
     * Syntax: "Key" > "Value"
     */
    void store_to_file(); //function to store to file



    /* GET AND SET KEY / VALUE PAIRS */

    /**
     * @brief get_pair Find pair given key in map
     * @param key std::string key
     * @return the value related to the key
     */
    std::string get_pair(std::string key);

    /**
     * @brief set_pair Make a new key and value pair to be added to the map
     * @param key std::string key
     * @param value std:string value
     */
    void set_pair(std::string key, std::string value);



    /* SET & GET FILE NAME AND LOCATION */

    /**
     * @brief set_file_name Function to set the name of the file
     * @param name std::string name of the file
     */
    void set_file_name(std::string name);


    /**
     * @brief set_location_name Function to set the location of the file
     * @param name std::string location of the file
     */
    void set_location_name(std::string location);


    /**
     * @brief get_filename Function to return file name
     * @return std::string fileName
     */
    std::string get_file_name();


    /**
     * @brief get_location_name Function to return location name
     * @return std::string location
     */
    std::string get_location_name();

private:

    /* Vars for Name and Location of the File */

    // Name of file
    std::string fName;

    // Location of the file
    std::string location;

    /* Vars for File Handling */

    // The file handler for input
    std::ifstream fh;

    // The file handler for output
    std::ofstream fhOut;

    /* Hash Map */

    // Create hash map of type string
    std::map<std::string, std::string> configMap;

};

#endif // CONFIGURATION_H
