#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Triangle", "[minimumTotal]")
{
    Solution s;
    SECTION( "example" )
    {
        vector<vector<int>> vec{{2},{3,4},{6,5,7},{4,1,8,3}};
        REQUIRE( s.minimumTotal(vec) == 11 );
    }
    SECTION( "complicated" )
    {
        vector<vector<int>> vec{{-7},{-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}};
        REQUIRE( s.minimumTotal(vec) == -63 );
    } 
}
