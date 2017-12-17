#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Longest Palindromic Substring", "longestPalindrome")
{
    Solution s;
    REQUIRE( s.longestPalindrome("abbabbua") == "bbabb");
}
