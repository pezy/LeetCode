#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Edit Distance", "[minDistance]")
{
    Solution s;
    REQUIRE( s.minDistance("graffe", "graf") == 2 );
    REQUIRE( s.minDistance("graffe", "graft") == 2 );
    REQUIRE( s.minDistance("graffe", "grail") == 3 );
    REQUIRE( s.minDistance("graffe", "giraffe") == 1 );
    REQUIRE( s.minDistance("intention", "execution") == 5 );
}
