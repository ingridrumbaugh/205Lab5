#include "configuration.h"

using namespace std;

/**
 * @brief Configuration::Configuration
 * This is the default constructor for the Configuration class.
 * It creates a new file handler which opens a txt file
 * named config.txt.
 * The constructor then saves name and location and reads in data
 * to the hash map.
 */
Configuration::Configuration () {
    try {
        SHOW_WHERE;
        // Open the file, named config.txt and truncate

        fh.open("./config.txt",std::ifstream::in | std::ifstream::app);

        //debugging
        std::cout<<"File state in constructor:"<<fh.is_open()<<endl;

        // Save name and location
        fName    = "config.txt";
        location = "./config.txt";

        // Read in data to the hash map
        read_in();

    }
    // Catch any exceptions / issues opening the file
    catch(std::exception_ptr *e) {
        std::cout<<"Unable to read in from file";
    }
}


/**
 * @brief Configuration::Configuration
 * This constructor saves the name and location
 * of the file, opens a new file handler, and reads in
 * data from the file.
 * @param name, name of the file to be opened.
 * @param location, location of the file.
 */
Configuration::Configuration(std::string location, std::string name) {
    SHOW_WHERE;

    // For debugging:
    // std::cout<<"in constructor:";

    // Save name and location of file
    fName          = name;
    this->location = location;

    // Open file
    fh.open(location,std::ifstream::in | std::ifstream::app);
    std::cout<<"File state:"<<fh.is_open()<<"\n";

    // Read in data from file and add to map
    read_in();
}


/**
 * @brief Configuration::~Configuration
 * This destructor closes the file handler,
 * Opens a new one to write out data,
 * then stores the hash map back into the file.
 */
Configuration::~Configuration() {
    SHOW_WHERE;
    // Debugging: Let us know we're at the destructor
    // cout<<"destructor:"<<configMap.size();

    // Close the file
    fh.close();

    // Truncate the file
    fhOut.open(location, std::ofstream::out | std::ofstream::trunc);
    // Store the hash data back to the file
    store_to_file();
    // Close the file
    fhOut.close();

}


/**
 * @brief Configuration::read_in
 * This method clears the existing map, reads each line of the file,
 * and then stores the key/value pair from that line into the map.
 */
void Configuration::read_in() {
    try {

        // Start with an empty map
        configMap.clear();

        // If the file exists, continue
        if(fh) {

               std::cout<<"File is open\n";

                // while we're not at the end of the file
                while(! fh.eof()) {

                    // Temp var for reading in lines from a file
                    std::string templine;
                    // Save the line in a temp variable
                    std::getline(fh,templine);

                    // Determine size of first line - If it's 0 then the line is empty
                    int size = templine.size();

                    if(size == 0)
                        continue;

                    else {

                        // Splitting the line up
                        // Find position
                        int position = 0;

                        // Look for the > character in the line (this is the delimiter)
                        position = templine.find(">");
                        // Get the key and value for the map
                        std::string key   = templine.substr(0, position);
                        std::string value = templine.substr(position+1, templine.size());

                        // Now this needs to be put in the hash map
                        std::cout<<"Key "<<key<<": Value "<<value<<endl;
                        // Put the key, value pair into the map
                        set_pair(key,value);
                    }
                }
           // }

        }

      // Catch any errors reading data from the file
    } catch(std::exception_ptr *e) {
        std::cout<<"Unable to read in from file \n";
    }

}


/**
 * @brief Configuration::store_to_file
 * This method stores the key, value pair to the file.
 * It stores the info in the order of: "key" > "value".
 */
void Configuration::store_to_file() {
    try {
        // Store size of hash map
        int sizemap = configMap.size();

        // If map is empty
        if(sizemap == 0) {
            cout << "Map is empty\n";
        }
        else {

            // Start iterator at the beginning of the map
            std::map<std::string, std::string>::iterator it = configMap.begin();

            // While we're not at the end of the file
            while(it != configMap.end()) {

                // Store key and value pair
                std::string key = it->first;
                std::string val = it->second;
                // Write key and value pair to the file, separated by >
                fhOut << key
                      << ">"
                      << val
                      << endl;
                // Write key and value pair to the command line
                std::cerr << "============="
                          << key
                          << ">"
                          << val
                          << "============="
                          << endl;
                // Increment iterator
                it++;
            }
        }
        // Catch any errors associated with writing to the file
    } catch(std::exception_ptr *e) {
        std::cout<<"Unable to write to file!\n";
    }
}


std::string Configuration::get_pair(std::string key) {
    // Define value
    std::string value ;
    // Find value stored at key in map
    value = configMap.find(key)->second;
    return value;
}


void Configuration::set_pair(std::string key, std::string value) {
    // Print the key value pair
    std::cout<<"Key "<<key<<": Value "<<value<<endl;

    // Insert key and pair into the hash map
    configMap.insert((std::make_pair(key,value)));
}


void Configuration::set_file_name(std::string name) {
    // Save the file name to variable fName
    fName = name;
    // Print the new name
    cout<<"The new name of the file is: "<<fName<<endl;
}


void Configuration::set_location_name(std::string location) {
    // Save the new location of the file
    this->location = location;
    // Print the new location of the file
    cout<<"The new location of the file is: "<<location<<endl;
}


std::string Configuration::get_file_name() {
    return fName;
}


std::string Configuration::get_location_name() {
 return location;
}


