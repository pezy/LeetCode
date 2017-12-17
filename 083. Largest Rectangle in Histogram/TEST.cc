#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Largest Rectangle in Histogram", "[largestRectangleArea]")
{
    Solution s;
    SECTION( "common1" )
    {
        std::vector<int> height{6, 2, 5, 4, 5, 1, 6};
        REQUIRE( s.largestRectangleArea(height) == 12 );
    }
    SECTION( "common2" )
    {
        std::vector<int> height{2, 1, 5, 6, 2, 3};
        REQUIRE( s.largestRectangleArea(height) == 10 );
    }
}
