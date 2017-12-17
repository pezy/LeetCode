#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Jump Game II", "[jump]")
{
    Solution s;
    SECTION( "example" )
    {
        int A[] = {2,3,1,1,4};
        REQUIRE( s.jump(A, 5) ==  2 );
    }

    SECTION( "failed" )
    {
        int A[] = {3,2,1,0,4};
        REQUIRE( s.jump(A, 5) == -1 );
    }
    SECTION( "less" )
    {
        int A[] = {0};
        REQUIRE( s.jump(A, 1) == 0 );
    }
}
