#include "log.h"
#include <iostream>
#include "configuration.h"

using namespace std;

/**
 * @brief main
 * This is the main method that is used
 * to test the Log and Configuration classes.
 * It prints the status of these programs to the
 * command line.
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    // Create new log file called Log.txt
    Log err_log2("./Log.txt","Log.txt",1);
    cout<<"File status:"<<err_log2.log_status()<<"\n";
    cout<<"\n";

    //Closing the log and checking the status
    err_log2.close_log();
    int state = err_log2.log_status();
    cout<<"File status:"<<state<<"\n";
    cout<<"\n";

    //Opening log again to append
    err_log2.open_log();
    cout<<"File status:"<<err_log2.log_status()<<"\n";
    cout<<"\n";

    //Adding strings
    err_log2 << "test" << "test" << "test" << "test";
    int test = 1;
    err_log2<<test;
    cout<<"\n";

    //Closing file
    err_log2.close_log();

    // Testing to see if file data is removed when opened empty
    Log err_log("./ErrLog.txt","ErrLog.txt",0);

    // Adding strings
    err_log << "test" << "test" << "test" << "test";
    err_log<<test;
    // Close the log file
    err_log.close_log();

    //Opening file to open file
    err_log.open_log_empty();

    //A dding data to file
    double test2 = 99.055;
    err_log<<test2;

    //Testing the configuration class

    // Create new instance of the configuration class

    //Implicitly testing readIn() by constructor
    Configuration config_1("./config.txt","config.txt");

    // Set two pairs for the map
    config_1.set_pair("a","1");
    config_1.set_pair("b","2");
    cout<<"\n";

    // Print out key, pair in map
    cout<<"\nFor key b:"<<config_1.get_pair("b");
    cout<<"\n";

    // Set file and location name
    config_1.set_file_name("newconfig.txt");
    config_1.set_location_name("./newconfig.txt");

    //adding a new line to the changed files.
    config_1.set_pair("d","4");
    config_1.set_pair("c","3");


    // Implicitly testing storeToFile() by destructor
    return 0;
}
