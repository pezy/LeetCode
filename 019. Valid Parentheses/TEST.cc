#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Valid Parentheses", "[isValid]")
{
    Solution s;
    REQUIRE( s.isValid("()") == true );
    REQUIRE( s.isValid("()[]{}") == true );
    REQUIRE( s.isValid("(]") == false );
    REQUIRE( s.isValid("([)]") == false );
    REQUIRE( s.isValid("]") == false );
}
