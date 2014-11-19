#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Search a 2D Matrix", "[searchMatrix]")
{
    Solution s;

    SECTION( "1" )
    {
        std::vector<std::vector<int> > vec{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
        REQUIRE( s.searchMatrix(vec, 3) == true );
    }

    SECTION( "2" )
    {
        std::vector<std::vector<int> > vec{{1},{1}};
        REQUIRE( s.searchMatrix(vec, 0) == false );
    }

    SECTION( "3" )
    {
        std::vector<std::vector<int> > vec{{1,3}};
        REQUIRE( s.searchMatrix(vec, 0) == false );
    }    
}
