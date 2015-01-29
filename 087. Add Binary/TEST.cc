#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Add Binary", "[addBinary]")
{
    Solution s;
    REQUIRE( s.addBinary("11", "1") == "100" );
    REQUIRE( s.addBinary("111", "10") == "1001" );
}
