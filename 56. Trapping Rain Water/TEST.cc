#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Trapping Rain Water", "[trap]")
{
    Solution s;
    
    SECTION( "Example" )
    {
        int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        REQUIRE( s.trap(A, 12) == 6 );
    }
    
    SECTION( "None" )
    {
        int A[] = {0,2,0};
        REQUIRE( s.trap(A, 3) == 0 );
    }
}




