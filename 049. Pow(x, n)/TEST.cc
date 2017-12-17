#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("pow (x, n)", "[pow]")
{
    Solution s;
    REQUIRE( s.pow(2.0, 3) == 8 );
    REQUIRE( s.pow(2.0, -3) == 0.125 );
    REQUIRE( s.pow(2.0, 4) == 16 );
    REQUIRE( s.pow(2.0, 0) == 1 );
}
