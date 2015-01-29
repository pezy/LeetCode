#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("find the single one of an array which other integers appears three times", "[singleNumber]")
{
    Solution s;

    SECTION( "size:7" )
    {
        int A[7] = {2,3,3,2,4,2,3};
        REQUIRE( s.singleNumber(A, 7) == 4 );
    }

    SECTION( "size:10" )
    {
        int A[10] = {4,5,3,3,5,5,3,6,4,4};
        REQUIRE( s.singleNumber(A, 10) == 6 );
    }

    SECTION( "size:13" )
    {
        int A[13] = {8,9,13,44,13,9,44,9,44,13,8,5,8};
        REQUIRE( s.singleNumber(A, 13) == 5 );
    }    
}
