#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Permutation Sequence", "[getPermutation]")
{
    Solution s;
    REQUIRE( s.getPermutation(3, 5) == "312" );
    REQUIRE( s.getPermutation(8, 31492) == "72641583" );
}
