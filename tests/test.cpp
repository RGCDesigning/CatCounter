#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/catcounter.cpp"

using namespace std;

TEST_CASE("testing toLower", "[Test 1]")
{
    string t1 = "";
    toLower(t1);
    REQUIRE( t1 == "" );

    string t2 = "Mylo Zaggy";
    toLower(t2);
    REQUIRE( t2 == "mylo zaggy" );

    string t3 = "THISISLOWERCASE";
    toLower(t3);
    REQUIRE( t3 == "thisislowercase" );

    string t4 = "12345";
    toLower(t4);
    REQUIRE( t4 == "12345" );

}

TEST_CASE("testing inputs with counter", "[Test 2]")
{
    string t1;
    string t2 = "\b\b";
    string t3 = "catcatcat";
    string t4 = "cat dog cat dog c a t d o g";
    string t5 = "     cat     ";

    REQUIRE( counter(t1) == -1 );
    REQUIRE( counter(t2) == 0 );
    REQUIRE( counter(t3) == 3 );
    REQUIRE( counter(t4) == 2 );
    REQUIRE( counter(t5) == 1 );
}

TEST_CASE("testing getInput", "[Test 3]")
{
    ifstream fakeCin;
    fakeCin.open("text_files/test_cin.txt", ifstream::in); 

    REQUIRE( fakeCin.is_open() == true );   //Will fail if not run from main directory
                                            //Run with run_tests.sh
    REQUIRE( getInput(fakeCin) == "ABC123" );

}

TEST_CASE("testing readFile", "[Test 4]")
{
    REQUIRE( readFile("this_does_not_exist.file") == "" );
    REQUIRE( readFile("text_files/test_cin.txt") == "ABC123" );
}

TEST_CASE("testing counter with two files", "[Test 5]")
{
    string t1 = readFile("text_files/kjv.txt");
    string t2 = readFile("text_files/test.txt");

    REQUIRE( counter(t1) == 539 );
    REQUIRE( counter(t2) == 1 ); //Only one is lowercase

}
