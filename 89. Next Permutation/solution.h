#include <vector>
using std::vector; using std::next; using std::prev;
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2) return;
        auto start = prev(num.end());
        for (;;) {
            auto last = start--;
            if (*start < *last) {
                auto riter = num.end();
                while (!(*start < *--riter)) ;
                std::iter_swap(start, riter);
                std::reverse(last, num.end());
                return;
            }
            if (start == num.begin()) {
                std::reverse(num.begin(), num.end());
                return;
            }
        }
    }
};
