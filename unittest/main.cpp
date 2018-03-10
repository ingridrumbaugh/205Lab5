#include <iostream>

#include "gtest/gtest.h"
#include "../tools/configuration.h"
#include "../tools/log.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:

    // Objects declared here can be used by all tests in the test case for Foo.

    /** Instances of classes **/
    Configuration s1;
    Configuration s2;
    Configuration config1;
    Log err_log;

};

/**
 * @brief TEST
 * If two instances of configuration class
 * are created, (One with the default, and one with
 * the same name / location, test that their
 * names and locations are the same.
 */
TEST(construct, TESTNEWCONSTRUCTOR) {

    /** Test File names **/
    Configuration s1;
    Configuration s2("./config.txt","config.txt");
    std::cout<<s1.get_file_name();
    std::cout<<s2.get_file_name();
    ASSERT_EQ(s1.get_file_name(), s2.get_file_name()) << s1.get_file_name()
                                                      << " and "
                                                      << s2.get_file_name()
                                                      << " should match!";
}

/**
 * @brief TEST
 * Test that get file name and location name methods work.
 */
TEST(construct, TESTDEFAULTCONSTRUCT) {
    // Standard constructor creates txt file called config
    Configuration config1;
    ASSERT_TRUE(config1.get_file_name()    == "config.txt"  );
    ASSERT_TRUE(config1.get_location_name() == "./config.txt");
}


/**
 * @brief TEST
 * Create two key/value pairs and test that
 * get_pair returns the correct value for the
 * specified key.
 * This also tests that if you use set_pair twice,
 * it works for the 2nd pair as well as the first.
 */
TEST(config, TESTGETPAIR) {
    Configuration config1;
    // Create keys and values
    std::string a = "a";
    std::string b = "b";
    std::string val1 = "1";
    std::string val2 = "2";
    // Set pairs
    config1.set_pair(a, val1);
    config1.set_pair(b,val2);
    // Test that they match
    ASSERT_TRUE(config1.get_pair(a) == val1);
    ASSERT_TRUE(config1.get_pair(b) == val2);
}

/**
 * @brief TEST
 * Test that setting a new file name for an instance
 * of configuration class returns the correct file name.
 * (and not the old one)
 */
TEST(config, TESTSETFILENAME) {
    Configuration config1;
    config1.set_file_name("newtestfile.txt");
    ASSERT_TRUE(config1.get_file_name() == "newtestfile.txt");
}

/**
 * @brief TEST
 * Test that setting a new location for a file works.
 * Use get_location_name() to test.
 */
TEST(config, TESTSETLOCATIONNAME) {
    Configuration config1;
    config1.set_location_name("./NewFolder/newtestfile.txt");
    ASSERT_EQ(config1.get_location_name(),"./NewFolder/newtestfile.txt");
}

/**
 * @brief TEST
 * Test the readin method.
 * Create once instance of configuration, add key/value pair.
 * Call destructor and make a 2nd instance (exactly the same as the first)
 * of configuration, add a 2nd key/value pair, and test that
 * both pairs exist in the 2nd instance.
 */
TEST(read, TESTREADIN) {

    //There should be a file called "readtest.txt" in the unittest directory
    //If it does not exist, add the following
    //"z>12"
    //Please only then continue with the function.
    //You can check by looking at "readtest2.txt"

    //Configuration config1("./readtest.txt","readtest.txt");

    // add info, call destructor
     std::string k1 = "z";
     std::string v1 = "12";

    // Open another instance w the same name, add new info
    Configuration config2("./readtest.txt","readtest.txt");
    std::string k2 = "w";
    std::string v2 = "32";
    config2.set_pair(k2, v2);

    // change name and location
     config2.set_file_name("readtest2.txt");
     config2.set_location_name("./readtest2.txt");

    ASSERT_TRUE(config2.get_pair(k1) == v1);
    ASSERT_TRUE(config2.get_pair(k2) == v2);
    //config2.~Configuration();
}



/**
 * @brief TEST Method that checks that creating an object of Log with
 *             a name and location also opens the file by checking the
 *             state of the file
 */
TEST(log, TESTFILEOPEN){
    Log l("./log.txt","log.txt",1);
    ASSERT_EQ(l.log_status(),1);
}


/**
 * @brief TEST Method that checks that creating an object of Log with
 *             default constructor also opens the file by checking the
 *             state of the file
 */
TEST(log, TESTFILEOPENDEFAULT){
    Log l;
    ASSERT_EQ(l.log_status(),1);
}


/**
 * @brief TEST Method that checks that closing the file by using the
 *             method called close_log closes the file by checking the
 *             state of the file
 */
TEST(log_file, TESTCLOSE){
    Log err_log;
    err_log.close_log();
    ASSERT_EQ(err_log.log_status(),0);
}

/**
 * @brief TEST Method that checks that opening the file by using the
 *             method called open_log open the file by checking the
 *             state of the file
 */
TEST(log_file, TESTOPEN){
    Log err_log;
    err_log.open_log();
    ASSERT_EQ(err_log.log_status(),1);
}

/**
 * @brief TEST Method that checks that one cannot open a file that is
 *             flushed but not closed
 */
TEST(log_file, TESTOPENWHENFLUSHED){
    Log err_log;
    err_log.flush_log();
    err_log.open_log();
    ASSERT_EQ(err_log.log_status(),2);
}

/**
 * @brief TEST Method that checks that flushing the file by using the
 *             method called flush_log flushes the file by checking the
 *             state of the file
 */
TEST(log_file, TESTFLUSH){
    Log err_log;
    err_log.flush_log();
    ASSERT_EQ(err_log.log_status(),2);
}

/**
 * @brief TEST Method that checks that one cannot flush a file that is
 *             closed
 */
TEST(log_file, TESTFLUSHWHENCLOSED){
    Log err_log;
    err_log.close_log();
    err_log.flush_log();
    ASSERT_EQ(err_log.log_status(),0);
}

/**
 * @brief TEST Method that checks that one cannot close a file that is
 *             closed. An exception is thrown
 */
TEST(log_file, TESTCLOSEWHENCLOSED){
    Log err_log;
    err_log.close_log();
    try{
        err_log.close_log();
    }
    catch (std::exception_ptr *e) {
        std::cout << "Error closing log file";
        bool state = true;
        ASSERT_TRUE(state);
    }

}

/**
 * @brief TEST Method to test that open_log_empty opens the same file
 *             but empty even if information already existed in it.
 *             Note the file must be closed for open_log_empty to work.
 */
TEST(log,TESTOPENEMPTY){

    try{
        Log err_log("./openlogempty.txt","openlogempty.txt",1);
        err_log << "Yes";
        double num = 99.02;
        err_log << num;
        err_log.close_log();
        err_log.open_log_empty();

        //open the file "openlogempty.txt" in the unittest directory
        //to see that the file is empty
    }
    catch (std::exception_ptr *e) {
        std::cout << "Error in test open empty";
        bool state = false;
        ASSERT_TRUE(state);
    }


}

/**
 * @brief TEST Testing that we can put strings of various lenghts into an
 *             open file.
 */
TEST(log, TESTPUTSTRING){
    try{
        Log err_log("./logteststring.txt","logteststring.txt",1);
        err_log << "This test works!";
        err_log << "This test checks if we can put strings in the file";

        //open the file "logteststring.txt" in the unittest directory
        //to see that the file has
        //the time stamp
        //" The test works "
        //" This test checks if we can put strings in the file "
        //on the same line
        //This should be similar to the "logteststringCompare.txt" file in
        //the same directory. Please note that the time will be different

    }
    catch (std::exception_ptr *e) {
        std::cout << "Error in test string input";
        bool state = false;
        ASSERT_TRUE(state);
    }

}

/**
 * @brief TEST Testing that we can put doubles of various lenghts into an
 *             open file.
 */
TEST(log, TESTPUTDOUBLE){
    try{
        Log err_log("./logtestdouble.txt","logtestdouble.txt",1);
        err_log << 99.01 ;
        err_log << 0.001 ;

        //open the file "logtestdouble.txt" in the unittest directory
        //to see that the file has
        //the time stamp
        //" 99.01 "
        //" 0.001 " on the same line
        //This should be similar to the "logtestdoubleCompare.txt" file in
        //the same directory. Please note that the time will be different

    }
    catch (std::exception_ptr *e) {
        std::cout << "Error in test double input";
        bool state = false;
        ASSERT_TRUE(state);
    }

}

/**
 * @brief TEST Testing that we can put ints of various lenghts into an
 *             open file.
 */
TEST(log, TESTPUTINT){
    try{
        Log err_log("./logtestint.txt","logtestint.txt",1);
        err_log << 100 ;
        err_log << 2001 ;

        //open the file "logtestint.txt" in the unittest directory
        //to see that the file has
        //the time stamp
        //" 100 "
        //" 2001 " on the same line
        //This should be similar to the "logtestintCompare.txt" file in
        //the same directory. Please note that the time will be different

    }
    catch (std::exception_ptr *e) {
        std::cout << "Error in test double input";
        bool state = false;
        ASSERT_TRUE(state);
    }

}


/**
 * @brief TEST Testing that we can put strings, doubles or ints
 *             of various lenghts into an open file.
 */
TEST(log, TESTPUTMLUTIPLE){
    try{
        Log err_log("./logtestmultiple.txt","logtestmultiple.txt",1);
        err_log << 100.001 ;
        err_log << " rounds to " ;
        err_log<< 100;

        //open the file "logtestmultiple.txt" in the unittest directory
        //to see that the file has
        //the time stamp
        //" 100.001 "
        //" rounds to "
        //" 100 " on the same line
        //This should be similar to the "logtestmultipleCompare.txt" file in
        //the same directory. Please note that the time will be different
    }
    catch (std::exception_ptr *e) {
        std::cout << "Error in test double input";
        bool state = false;
        ASSERT_TRUE(state);
    }
}



int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
