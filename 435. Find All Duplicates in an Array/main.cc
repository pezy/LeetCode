#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Find All Duplicates in an Array", "[findDuplicates]")
{
    SECTION( "as question" )
    {
        std::vector<int> vec{4,3,2,7,8,2,3,1};
        std::vector<int> ret{2,3};
        Solution s;
        REQUIRE( s.findDuplicates(vec) == ret );
    }
}
