#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Regular Expression Matching", "isMatch")
{
    Solution s;

    REQUIRE_FALSE(s.isMatch("aa", "a"));
    REQUIRE(s.isMatch("aa", "aa"));
    REQUIRE_FALSE(s.isMatch("aaa", "aa"));
    REQUIRE(s.isMatch("aa", "a*"));
    REQUIRE(s.isMatch("aa", ".*"));
    REQUIRE(s.isMatch("ab", ".*"));
    REQUIRE(s.isMatch("aab", "c*a*b"));
}
