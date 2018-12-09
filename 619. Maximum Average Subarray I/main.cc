#include "solution.h"
#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"

TEST_CASE("Test findMaxAverage", "[vector]") {
  Solution s;
  SECTION("example case") {
    std::vector<int> arr{1, 12, -5, -6, 50, 3};
    int k = 4;
    double ans = s.findMaxAverage(arr, k);
    REQUIRE(ans == 12.75);
  }
  SECTION("include zero") {
    std::vector<int> arr{0, 4, 0, 3, 2};
    int k = 1;
    double ans = s.findMaxAverage(arr, k);
    REQUIRE(ans == 4.0);
  }
}
