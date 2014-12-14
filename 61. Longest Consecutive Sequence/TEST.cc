#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Longest Consecutive Sequence", "[longestConsecutive]")
{
    Solution s;
    SECTION( "common" )
    {
        vector<int> vec{100, 4, 200, 1, 3, 2};
        REQUIRE( s.longestConsecutive(vec) == 4 );
    }

    SECTION( "max" )
    {
        vector<int> vec{0,3,7,2,5,8,4,6,0,1};
        REQUIRE( s.longestConsecutive(vec) == 9 );    
    }
}
