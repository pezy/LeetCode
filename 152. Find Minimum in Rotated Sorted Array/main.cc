#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"
#include <iostream>

TEST_CASE("Find Minimum in Rotated Sorted Array", "[findMin]")
{
    SECTION( "as question" )
    {
        std::vector<int> vec{4,5,6,7,0,1,2};
        Solution s;
        REQUIRE( s.findMin(vec) == 0 );
    }
    
    SECTION( "case more" )
    {
        std::vector<int> vec{1,2};
        Solution s;
        REQUIRE( s.findMin(vec) == 1 );
    }
}
