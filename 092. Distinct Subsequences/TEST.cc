#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Distinct Subsequences", "[numDistinct]")
{
    Solution s;
    REQUIRE( s.numDistinct("", "") == 1 );
    REQUIRE( s.numDistinct("123", "") == 1 );
    REQUIRE( s.numDistinct("", "123") == 0 );
    REQUIRE( s.numDistinct("b", "a") == 0 );
    REQUIRE( s.numDistinct("ABCDE", "ACE") == 1 );
    REQUIRE( s.numDistinct("ABCDE", "AEC") == 0 );
    REQUIRE( s.numDistinct("AAA", "A") == 3 );
    REQUIRE( s.numDistinct("rabbbit", "rabbit") == 3 );

}
