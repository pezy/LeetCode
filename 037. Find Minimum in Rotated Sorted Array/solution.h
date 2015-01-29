#include <vector>
using std::vector; using std::next; using std::prev; using std::advance;

class Solution {
public:
    int findMin(vector<int> &num) {
        auto beg = num.begin();
        for (auto end = std::prev(num.end()); beg < end; )
        {
            if (*beg < *end) break;
            auto mid = (end - beg) >> 1;
            *beg <= *next(beg, mid) ? advance(beg, mid+1) : advance(end, -mid);
        }
        return *beg;
    }
};
