#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("3Sum Closest", "[threeSumClosest]")
{
    Solution s;
    SECTION( "common" )
    {
        std::vector<int> vec{-1,2,1,-4};
        REQUIRE( s.threeSumClosest(vec, 1) == 2 );
    }
    SECTION( "target is small" )
    {
        std::vector<int> vec{1,1,1,0};
        REQUIRE( s.threeSumClosest(vec, -100) == 2 );
    }
}
