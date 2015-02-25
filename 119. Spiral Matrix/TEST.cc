#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Spiral Matrix", "spiralOrder")
{
    Solution s;
    SECTION( "Example" )
    {
        std::vector<std::vector<int>> matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}

        };
        std::vector<int> ret{1,2,3,6,9,8,7,4,5};
        REQUIRE(s.spiralOrder(matrix) == ret);
    }
    SECTION( "One line" )
    {
        std::vector<std::vector<int>> matrix = {{6,9,7}};
        std::vector<int> ret{6,9,7};
        REQUIRE(s.spiralOrder(matrix) == ret);
    }
    SECTION( "Two line" )
    {
        std::vector<std::vector<int>> matrix = {
            {1,2,3,4,5,6,7,8,9,10},
            {11,12,13,14,15,16,17,18,19,20}
        };
        std::vector<int> ret{1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
        REQUIRE(s.spiralOrder(matrix) == ret);
    }
    SECTION( "One Column" )
    {
        std::vector<std::vector<int>> matrix = {{7}, {9}, {6}};
        std::vector<int> ret{7,9,6};
        REQUIRE(s.spiralOrder(matrix) == ret);
    }
}
