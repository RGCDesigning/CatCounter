#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/catcounter.cpp"

using namespace std;

TEST_CASE("Test 1", "[Test 1]")
{
    string t = "This is a test";

    REQUIRE( counter(t) == 0 );
}
