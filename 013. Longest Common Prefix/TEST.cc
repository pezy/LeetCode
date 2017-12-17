#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Longest Common Prefix", "[longestCommonPrefix]")
{
    Solution s;
    SECTION( "common" )
    {
        std::vector<std::string> vec{"hello", "helo", "heat", "hey"};
        REQUIRE( s.longestCommonPrefix(vec) == "he" );
    }
    SECTION( "less than first" )
    {
        std::vector<std::string> vec{"aa", "a"};
        REQUIRE( s.longestCommonPrefix(vec) == "a" );
    }
}
