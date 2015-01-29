#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"
using std::vector;

TEST_CASE("First Missing Positive", "[firstMissingPositive]")
{
    Solution s;
    SECTION( "example" )
    {
        vector<int> vec{6,1,3,2,4,7,6,10,15};
        REQUIRE( s.maxProfit(vec) == 15 );
    }
    SECTION( "empty" )
    {
        vector<int> vec;
        REQUIRE( s.maxProfit(vec) == 0 );
    }
}
