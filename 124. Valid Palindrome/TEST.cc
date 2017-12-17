#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Valid Palindrome", "[isPalindrome]")
{
    Solution s;
    REQUIRE(s.isPalindrome("A man, a plan, a canal: Panama"));
    REQUIRE_FALSE(s.isPalindrome("race a car"));
    REQUIRE(s.isPalindrome("''''''''''''''''''''''''''''''"));
}
