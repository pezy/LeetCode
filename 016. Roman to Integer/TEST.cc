#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("roman can covert to integer", "[romanToInt]")
{
    Solution s;
    REQUIRE( s.romanToInt("IV") == 4 );
    REQUIRE( s.romanToInt("IX") == 9 );
    REQUIRE( s.romanToInt("XL") == 40 );
    REQUIRE( s.romanToInt("XC") == 90 );
    REQUIRE( s.romanToInt("CD") == 400 );
    REQUIRE( s.romanToInt("CM") == 900 );
    REQUIRE( s.romanToInt("MMXIV") == 2014 );
    REQUIRE( s.romanToInt("MDCCCLXXXIV") == 1884 );
}
