#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Longest Substring Without Repeating Characters", "[lengthOfLongestSubstring]")
{
    Solution s;
    REQUIRE( s.lengthOfLongestSubstring("abcabcbb") == 3 );
    REQUIRE( s.lengthOfLongestSubstring("bbbbb") == 1 );
    REQUIRE( s.lengthOfLongestSubstring("a") == 1 );
    REQUIRE( s.lengthOfLongestSubstring("au") == 2 );
    REQUIRE( s.lengthOfLongestSubstring("bwt") == 3 );
    REQUIRE( s.lengthOfLongestSubstring("abba") == 2 );
}
