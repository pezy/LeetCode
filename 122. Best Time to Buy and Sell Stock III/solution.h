#include <vector>
using std::vector;
#include <algorithm>
using std::min; using std::max;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int low = prices.front(), high = prices.back(), ret = 0;
        vector<int> history; history.reserve(prices.size());
        for (auto today : prices) {
            low = min(low, today);
            ret = max(ret, today - low);
            history.push_back(ret);
        }
        for (auto today = prices.crbegin(), past = history.crbegin(); today != prices.crend(); ++today, ++past) {
            high = max(high, *today);
            ret = max(ret, *past + high - *today);
        }
        return ret;
    }
};
