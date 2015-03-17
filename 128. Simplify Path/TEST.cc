#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Regular Expression Matching", "isMatch")
{
    Solution s;

    REQUIRE( s.simplifyPath("/home/") == "/home" );
    REQUIRE( s.simplifyPath("/a/./b/../../c/") == "/c" );
    REQUIRE( s.simplifyPath("/../") == "/" );
    REQUIRE( s.simplifyPath("/home//foo/") == "/home/foo" );
    REQUIRE( s.simplifyPath("/.") == "/" );
    REQUIRE( s.simplifyPath("/...") == "/..." );
}
