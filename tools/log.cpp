#include "log.h"


/**
 * @brief Log::Log
 * The file handler is opened with preset file name, Lab2LogFile.txt
 * The file status is also set (open or closed)
 * The state append is assumed, the user cannot
 * choose between append or truncate here.
 */
Log::Log() {
    try {
        SHOW_WHERE;
        // Open the file with preset name, append to the end of the file
        fh.open("./Lab2LogFile.txt", std::ofstream::out | std::ofstream::app);

        // Store name and location of the file
        fileName     = "Lab2LogFile.txt";
        fileLocation = "./Lab2LogFile.txt";

        // Write time stamp to the log file
        // Not required by lab but we thought it would be useful
        //        std::time_t t = std::time(nullptr);
        //        fh << std::put_time(std::localtime(&t), "\n%c %Z\n");

        // Determine state of the file
        if(fh.is_open()) fileStatus = 1;
        else             fileStatus = 0;
    }
    catch(std::exception_ptr *e) {
        std::cout << "Error creating log file";
    }
}


/**
 * @brief Log::Log paramterised constructor that open the file at a given
 *                 location with a given name and asks the user whether
 *                 to append to existing file
 *                 or to start clean slate
 * @param location Location of file
 * @param name Name of file
 * @param blowItAway whether the file is to be cleared or not. 0->no, 1->yes
 */
Log::Log(std::string location,std::string name, bool blowItAway) {
    try {
        SHOW_WHERE;
        // Store the file location
        fileLocation = location;

        // Open the file in the correct location
        // Depending on state of bool blowItAway, either truncate or append
        if(blowItAway){
            fh.open(fileLocation, std::ofstream::out| std::ofstream::trunc );
        }else{
            fh.open(fileLocation, std::ofstream::out | std::ofstream::app );
        }

        // Write time stamp to the log file
        // Not required by lab but we thought it would be useful
        std::time_t t = std::time(nullptr);
        fh << std::put_time(std::localtime(&t), "\n%c %Z\n");

        // Store the file name
        fileName = name;

        //Determine the state of the file in boolean fileStatus
        if(fh.is_open()) fileStatus = 1;
        else             fileStatus = 0;

    } catch (std::exception_ptr *e) {
        std::cout << "Error creating log file";
    }
}


/**
 * @brief Log::~Log
 * The destructor in which the file handler is closed.
 */
Log::~Log() {

    try {
        SHOW_WHERE;
        // Close the file
        fh.close();
    }
    catch (std::exception_ptr *e) {
        std::cout << "Error closing log file";
    }

}


/**
 * @brief Log::operator <<
 * The overloaded operator will process the
 * incoming string, then return itself as a reference.
 * This allows chaining of multiple filehandler operations.
 * @param str
 */
Log& Log::operator<<(std::string str) {

    fh  << str << " ";

    fileStatus = 1; // file is opened and needs to be flushed like a toilet
    return *this;
}


/**
 * @brief Log::operator <<
 * The overloaded operator will process the incoming
 * double, then return itself as a reference.
 * This allows chaining of multiple filehandler operations.
 * @param x double number
 */
Log& Log::operator<<(double x) {

    fh  << x << " ";

    fileStatus = 1; // file is opened and needs to be flushed like a toilet
    return *this;
}


/**
 * @brief Log::operator <<
 * The overloaded operator will process the incoming
 * int,then return itself as a reference.
 * This allows chaining of multiple filehandler operations.
 * @param i int value
 */
Log& Log::operator<<(int i) {

    fh  << i << " ";

    fileStatus = 1; // file is opened and needs to be flushed like a toilet
    return *this;
}


/**
 * @brief Log::close_log
 * Method that closes the file if it is open.
 */
void Log::close_log() {
    try {
        // If file is open, then close it
        if(fileStatus != 0) {

            fh.close();

            // Change the status of the file once closed
            fileStatus = 0;
        }
    }
    catch (std::exception_ptr *e) {
        std::cout << "Error closing log file";
    }
}


/**
 * @brief Log::flush_log
 * Function that flushes an open file.
 */
void Log::flush_log() {
    try {
        // If file has already been flushed, return.
        if(fileStatus == 2) return;

        // If file hasn't been flushed, then flush and update state of file
        if(fileStatus == 1) {
            fh.flush();
            fileStatus = 2;
        }

    } catch (std::exception_ptr *e) {
        std::cout << "Error closing log file";
    }
}


/**
 * @brief Log::log_status
 * Returns the status of the file: Closed-0, Open-1, Flushed-2
 * @return int: status of the file
 */
int Log::log_status() {
    return fileStatus;
}


/**
 * @brief Log::open_log
 * This method will allow the user to open the
 * file. The name will be the one that is created
 * when the constructor is called.
 */
void Log::open_log() {
    try {
        if(fileStatus == 0) {
            // Open the file, append to end
            fh.open(fileLocation, std::ofstream::out | std::ofstream::app );

            // Write time stamp to the log file
            // Not required by lab but we thought it would be useful
            std::time_t t = std::time(nullptr);
            fh << std::put_time(std::localtime(&t), "\n%c %Z\n");

            // Update status of the file
            if(fh.is_open()) fileStatus = 1;
            else             fileStatus = 0;
        }
    }
    catch(std::exception_ptr *e) {
        std::cout << "Error opening log file";
    }
}


/**
 * @brief Log::open_log_empty
 * This function will allow the user to open
 * the file to an empty file.
 * The name will be the one that is created
 * when the constructor is called.
 */
void Log::open_log_empty() {
    try {
        if(fileStatus == 0) {
            // Open the file, truncate
            fh.open(fileLocation, std::ofstream::out | std::ofstream::trunc);

            // Write time stamp to the log file
            // Not required by lab but we thought it would be useful
            std::time_t t = std::time(nullptr);
            fh << std::put_time(std::localtime(&t), "\n%c %Z\n");

            // Update status of the file
            if(fh.is_open()) fileStatus = 1;
            else             fileStatus = 0;
        }                    fileStatus = 0;
    }
    catch(std::exception_ptr *e) {
        std::cout << "Error opening log file";
    }
}

