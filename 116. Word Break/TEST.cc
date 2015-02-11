#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Maximal Rectangle", "[maximalRectangle]")
{
    Solution s;
    SECTION( "Example" )
    {
        std::unordered_set<std::string> uset{"Leet", "Code"};
        REQUIRE( s.wordBreak("LeetCode", uset) );
    }
    SECTION( "CASE0" )
    {
        std::unordered_set<std::string> uset{"aaaa", "aaa"};
        REQUIRE( s.wordBreak("aaaaaaa", uset) );
    }
    SECTION( "CASE1" )
    {
        std::unordered_set<std::string> uset{"a","b","bbb","bbbb"};
        REQUIRE( s.wordBreak("bb", uset) );
    }
    SECTION( "CASE2" )
    {
        std::unordered_set<std::string> uset{"a"};
        REQUIRE( s.wordBreak("a", uset) );
    }
    SECTION( "CASE3" )
    {
        std::unordered_set<std::string> uset{"go","goal","goals","special"};
        REQUIRE( s.wordBreak("goalspecial", uset) );
    }
    SECTION( "CASE4" )
    {
        std::unordered_set<std::string> uset{"aaaa", "aa"};
        REQUIRE_FALSE( s.wordBreak("aaaaaaa", uset) );
    }
}
