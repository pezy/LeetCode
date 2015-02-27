#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

std::vector<int> showIntervals(const std::vector<Interval> &intervals) {
    std::vector<int> ret;
    for (const auto &interval : intervals) {
        ret.push_back(interval.start);
        ret.push_back(interval.end);
    }
    return ret;
}

TEST_CASE("Insert Interval", "insert")
{
    Solution s;

    SECTION("Example 1")
    {
        std::vector<Interval> vec{Interval(1,3), Interval(6,9)};
        Interval newInterval(2,5);
        std::vector<int> ret{1,5,6,9};
        REQUIRE(ret == showIntervals(s.insert(vec, newInterval)));
    }
    SECTION("Example 2")
    {
        std::vector<Interval> vec{Interval(1,2),Interval(3,5),Interval(6,7),Interval(8,10),Interval(12,16)};
        Interval newInterval(4,9);
        std::vector<int> ret{1,2,3,10,12,16};
        REQUIRE(ret == showIntervals(s.insert(vec, newInterval)));
    }
}
