#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Multiply Strings", "multiply")
{
    Solution s;

    REQUIRE(s.multiply("123456", "789") == "97406784");
    REQUIRE(s.multiply("123456789", "987654321") == "121932631112635269");
}
