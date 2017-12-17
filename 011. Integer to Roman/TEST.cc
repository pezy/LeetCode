#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("integer can covert to roman", "[intToRoman]")
{
    Solution s;
    REQUIRE( s.intToRoman(1904) == "MCMIV" );
    REQUIRE( s.intToRoman(1954) == "MCMLIV" );
    REQUIRE( s.intToRoman(1990) == "MCMXC" );
    REQUIRE( s.intToRoman(2014) == "MMXIV" );
    REQUIRE( s.intToRoman(1066) == "MLXVI" );
}
