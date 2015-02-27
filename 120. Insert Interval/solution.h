#include <vector>
using std::vector;
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto low = std::lower_bound(intervals.cbegin(), intervals.cend(), newInterval, [](const Interval& lhs, const Interval& rhs){
            return lhs.start < rhs.start;
        });
        if (low != intervals.cbegin() && std::prev(low)->end >= newInterval.start) { --low; newInterval.start = low->start; }
        auto up = std::lower_bound(intervals.cbegin(), intervals.cend(), newInterval, [](const Interval& lhs, const Interval& rhs){
            return lhs.end < rhs.end;
        });
        if (up != intervals.cend() && up->start <= newInterval.end) { newInterval.end = up->end; ++up; }
        auto insert_pos = intervals.erase(low, up);
        intervals.insert(insert_pos, newInterval);
        return intervals;
    }
};
