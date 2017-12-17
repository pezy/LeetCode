#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Sqrt(x) ", "[sqrt]")
{
    Solution s;
    REQUIRE( s.sqrt(4) == 2 );
    REQUIRE( s.sqrt(10) == 3 );
}
