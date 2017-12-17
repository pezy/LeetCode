#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"
#include <iostream>

TEST_CASE("remove elements of an array", "[removeElement]")
{
    SECTION( "1" )
    {
        int arr[] = {1,3,4,5,3,6,8,9};
        Solution s;
        REQUIRE( s.removeElement(arr, 8, 3) == 6 );
    }
    
    SECTION( "2" )
    {
        int arr[] = {4,2,0,2,2,1,4,4,1,4,3,2};
        Solution s;
        REQUIRE( s.removeElement(arr, 12, 4) == 8 );
    }
    
    SECTION( "3" )
    {
        int arr[] = {0,3,1,1,0,1,3,0,3,3,1,1};
        Solution s;
        REQUIRE( s.removeElement(arr, 12, 1) == 7 );
    }
    
    SECTION( "3" )
    {
        int arr[] = {1};
        Solution s;
        REQUIRE( s.removeElement(arr, 1, 1) == 0 );
    }
    
    SECTION( "4" )
    {
        int arr[] = {2,2,3};
        Solution s;
        REQUIRE( s.removeElement(arr, 3, 3) == 2 );
    }
    
    SECTION( "5" )
    {
        int arr[] = {3,3};
        Solution s;
        REQUIRE( s.removeElement(arr, 2, 3) == 0 );
    }
}




