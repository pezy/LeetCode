#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Maximal Rectangle", "[maximalRectangle]")
{
    Solution s;
    SECTION( "common1" )
    {
        std::vector<std::vector<char>> matrix = {{'0', '1', '0', '0'},
                                                 {'1', '1', '1', '0'},
                                                 {'0', '1', '1', '0'},
                                                 {'0', '0', '1', '0'},
                                                 {'0', '1', '0', '0'}};
        REQUIRE( s.maximalRectangle(matrix) == 4 );
    }
    SECTION( "common2" )
    {
        std::vector<std::vector<char>> matrix = {{'1', '1', '1', '1'},
                                                 {'1', '0', '0', '1'},
                                                 {'1', '1', '1', '1'},
                                                 {'0', '0', '1', '0'},
                                                 {'0', '1', '1', '1'}};
        REQUIRE( s.maximalRectangle(matrix) == 4 );
    }
    SECTION( "common3" )
    {
        std::vector<std::vector<char>> matrix = {{'1', '1', '1', '1', '1'},
                                                 {'1', '1', '1', '0', '1'},
                                                 {'1', '1', '1', '0', '0'},
                                                 {'1', '0', '0', '0', '0'},
                                                 {'1', '0', '0', '0', '0'}};
        REQUIRE( s.maximalRectangle(matrix) == 9 );
    }
    SECTION( "common4" )
    {
        std::vector<std::vector<char>> matrix = {{'0', '1', '0', '1', '0'},
                                                 {'1', '1', '1', '1', '1'},
                                                 {'0', '1', '1', '1', '0'},
                                                 {'0', '1', '1', '1', '0'},
                                                 {'1', '1', '1', '1', '1'},
                                                 {'1', '1', '1', '1', '0'},
                                                 {'0', '1', '0', '1', '0'},
                                                 {'0', '0', '0', '0', '0'}};
        REQUIRE( s.maximalRectangle(matrix) == 15 );
    }
}
