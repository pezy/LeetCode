#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("ZigZag Conversion", "[convert]")
{
    Solution s;
    REQUIRE( s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR" );
    REQUIRE( s.convert("ABCDE", 4) == "ABCED" );
}
