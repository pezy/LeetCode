#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Search in Rotated Sorted Array", "[search]")
{
    SECTION( "common" )
    {
        int arr[] = {0,1,2,4,5,6,7};
        Solution s;
        REQUIRE( s.search(arr, 7, 2) == 2 );
    }
    
    SECTION( "rotated" )
    {
        int arr[] = {4,5,6,7,0,1,2};
        Solution s;
        REQUIRE( s.search(arr, 7, 3) == -1 );
    }
    
    SECTION( "extreme case" )
    {
        int arr[] = {3,1};
        Solution s;
        REQUIRE( s.search(arr, 2, 1) == 1 );
    }
}




