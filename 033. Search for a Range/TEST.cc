#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

using std::vector;

TEST_CASE("Search for a Range", "[searchRange]")
{
    Solution s;
    SECTION( "common" )
    {
        int A[] = {5, 7, 7, 8, 8, 10};
        vector<int> ret{3,4};
        REQUIRE( s.searchRange(A, 6, 8) ==  ret);
    }

    SECTION( "no" )
    {
        int A[] = {1};
        vector<int> ret{-1,-1};
        REQUIRE( s.searchRange(A, 1, 0) == ret );
    }
    
    SECTION( "all" )
    {
        int A[] = {2,2};
        vector<int> ret{0,1};
        REQUIRE( s.searchRange(A, 2, 2) == ret );
    }
}
