#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Implement strStr()", "[strStr]")
{
    Solution s;
    SECTION( "empty" )
    {
        char haystack[] = "";
        char needle[] = "";
        char other[] = "something";
        REQUIRE( s.strStr(haystack, needle) == 0 );
        REQUIRE( s.strStr(haystack, other) == -1 );
        REQUIRE( s.strStr(other, needle) == 0 );
    }
    SECTION( "common" )
    {
        char haystack[] = "whoisyourdady";
        char needle[] = "your";
        char other[] = "p";
        REQUIRE( s.strStr(haystack, needle) == 5 );
        REQUIRE( s.strStr(haystack, other) == -1 );
    }
}
