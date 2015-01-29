#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("totalNQueens is computed", "[totalNQueens]")
{
    Solution s;
    REQUIRE( s.totalNQueens(1) == 1 );
    REQUIRE( s.totalNQueens(2) == 0 );
    REQUIRE( s.totalNQueens(3) == 0 );
    REQUIRE( s.totalNQueens(4) == 2 );
    REQUIRE( s.totalNQueens(5) == 10 );
    REQUIRE( s.totalNQueens(6) == 4 );
    REQUIRE( s.totalNQueens(7) == 40 );
    REQUIRE( s.totalNQueens(8) == 92 );
    REQUIRE( s.totalNQueens(9) == 352 );
    REQUIRE( s.totalNQueens(10) == 724 );
    REQUIRE( s.totalNQueens(11) == 2680 );
    REQUIRE( s.totalNQueens(12) == 14200 );
}
