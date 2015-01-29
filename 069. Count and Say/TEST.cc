#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Count and Say", "[countAndSay]")
{
    Solution s;
    REQUIRE( s.countAndSay(1) == "1" );
    REQUIRE( s.countAndSay(2) == "11" );
    REQUIRE( s.countAndSay(3) == "21" );
    REQUIRE( s.countAndSay(4) == "1211" );
    REQUIRE( s.countAndSay(5) == "111221" );
    REQUIRE( s.countAndSay(6) == "312211" );
    REQUIRE( s.countAndSay(7) == "13112221" );
    REQUIRE( s.countAndSay(8) == "1113213211" );
}
