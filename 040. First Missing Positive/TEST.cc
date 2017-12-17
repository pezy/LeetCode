#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("First Missing Positive", "[firstMissingPositive]")
{
    Solution s;
    SECTION( "example1" )
    {
        int A[] = {1,2,0};
        REQUIRE( s.firstMissingPositive(A, 3) == 3);
    }

    SECTION( "example2" )
    {
        int A[] = {3,4,-1,1};
        REQUIRE( s.firstMissingPositive(A, 4) == 2);
    }

    SECTION( "empty" )
    {
        int A[] = {};
        REQUIRE( s.firstMissingPositive(A, 0) == 1);
    }

    SECTION( "one" )
    {
        int A[] = {1};
        REQUIRE( s.firstMissingPositive(A, 1) == 2);
    }

    SECTION( "one2" )
    {
        int A[] = {2};
        REQUIRE( s.firstMissingPositive(A, 1) == 1);
    }

    SECTION( "repeat" )
    {
        int A[] = {1,1};
        REQUIRE( s.firstMissingPositive(A, 2) == 2);
    }
}
