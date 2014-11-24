#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"
#include <iostream>

TEST_CASE("Search in Rotated Sorted Array", "[search]")
{
    SECTION( "1" )
    {
        int arr[] = {0,1,1,2,2,3,3};
        Solution s;
        REQUIRE( s.search(arr, 7, 1) == true );
    }
    
    SECTION( "2" )
    {
        int arr[] = {0,1,1,3,3,5,5};
        Solution s;
        REQUIRE( s.search(arr, 7, 4) == false );
    }
    
    SECTION( "3" )
    {
        int arr[] = {1,1,3,1};
        Solution s;
        REQUIRE( s.search(arr, 4, 3) == true );
    }
}




