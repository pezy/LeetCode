#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Palindrome Number", "[isPalindrome]")
{
    Solution s;
    REQUIRE( s.isPalindrome(2002) == true );
    REQUIRE( s.isPalindrome(-1001) == false );
}
