#include <vector>
#include <algorithm>
using std::vector; using std::max; using std::min;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int ret{0}, low{prices[0]};
        for (auto price : prices)
        {
            low = min(low, price);
            ret = max(ret, price - low);
        }
        return ret;
    }
};
