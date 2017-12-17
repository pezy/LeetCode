#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Jump Game", "[canJump]")
{
    Solution s;
    SECTION( "common1" )
    {
        int A[] = {2,3,1,1,4};
        REQUIRE( s.canJump(A, 5) ==  true );
    }

    SECTION( "common2" )
    {
        int A[] = {3,2,1,0,4};
        REQUIRE( s.canJump(A, 5) == false );
    }
    SECTION( "less" )
    {
        int A[] = {1};
        REQUIRE( s.canJump(A, 1) == true );
    }
}
