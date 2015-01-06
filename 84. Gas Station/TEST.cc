#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Gas Station", "[canCompleteCircuit]")
{
    Solution s;
    SECTION( "example" )
    {
        vector<int> gas{3,4,5};
        vector<int> cost{4,5,3};
        REQUIRE( s.canCompleteCircuit(gas, cost) == 2 );
    }
    SECTION( "complicated" )
    {
        vector<int> gas{3,4,5};
        vector<int> cost{3,5,4};
        REQUIRE( s.canCompleteCircuit(gas, cost) == 2 );
    } 
}
