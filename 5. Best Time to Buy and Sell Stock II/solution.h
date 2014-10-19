#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (auto i = prices.begin(); i != prices.end(); ++i)
            if (i+1 != prices.end() && *(i+1) > *i) profit += *(i+1) - *i;
        return profit;
    }
};
