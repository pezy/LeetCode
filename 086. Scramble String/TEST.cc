#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Scramble String", "[isScramble]")
{
    Solution s;
    REQUIRE(s.isScramble("great", "rgtae"));
    REQUIRE_FALSE(s.isScramble("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba"));
}
