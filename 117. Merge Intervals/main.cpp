#include "solution.h"
#include <iostream>

using namespace std;

int main() {
    Solution s;
    vector<Interval> vec = {
        Interval(15,18),
        Interval(8,10),
        Interval(2,6),
        Interval(1,3)
    };
    
    for (const auto &interval : s.merge(vec)) {
        std::cout << "[" << interval.start << "," << interval.end << "]" << ",";
    }
    std::cout << "\b " << std::endl;
}
