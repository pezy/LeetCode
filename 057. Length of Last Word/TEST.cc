#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Length of Last Word", "[lengthOfLastWord]")
{
    Solution s;
    REQUIRE( s.lengthOfLastWord("a ") == 1 );
    REQUIRE( s.lengthOfLastWord("Hello World") == 5 );
}
