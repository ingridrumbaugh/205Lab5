#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include "macro.h"
#include "baseclass.h"

/**
  * The following #includes were added so that a
  * time stamp could be added to the log file.
  *
  */
#include <chrono>
#include <iomanip>
#include <ctime>


class Log : public BaseClass {
public:

    /* CONSTRUCTORS & DESTRUCTORS */

    /**
     * @brief Log default constructor.
     * Opens a file with a preset name and location.
     */
    Log();


    /**
     * @brief Log constructor accepting name, location, and state of file
     *            (append or truncate)
     * @param location: Location of the file
     * @param name: Name (and extension) of the file
     * @param blowItAway: Determines whether previous file info is saved
     */
    Log(std::string location, std::string name, bool blowItAway);


    /**
      * @brief ~Log default deconstructor
      */
    ~Log();


    /* OVERLOADED HANDLER OPERATORS
     * The overloaded operator can be replicated multiple
     * times with different data types to allow different
     * kinds of information to be written to the log file.
     */

    /**
     * @brief operator << The overloaded handler operator for string
     */
    Log& operator<<(const std::string str);

    /**
     * @brief operator << The overloaded handler operator for double
     */
    Log& operator<<(double x);

    /**
     * @brief operator << The overloaded handler operator for int i
     */
    Log& operator<<(int i);

    /* FILE OPERATIONS */

    /**
     * @brief close_log
     * Close the file if open
     */
    void close_log();

    /**
     * @brief flush_log
     * Flush the file
     */
    void flush_log();

    /**
     * @brief log_status
     * Closed-0, Open-1, Flushed-2
     * @return Status of the file
     */
    int log_status();

    /**
     * @brief open_log
     * Open the log file
     */
    void open_log();

    /**
     * @brief open_log_empty
     * Open an empty log file
     */
    void open_log_empty();

private:

    /* VARIABLES FOR MANIPULATING FILES */

    // The file handler.
    std::ofstream fh;

    // The file name.
    std::string fileName;

    // The file location
    std::string fileLocation;

    // Status of the file:
    // 0 = closed; 1 = open; 2 = flushed
    int fileStatus;
};

#endif // LOG_H
