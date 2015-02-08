#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_map>
#include <set>

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int>>{};
        std::set<vector<int>> ret;
        std::sort(num.begin(), num.end());
        std::unordered_map<int, vector<std::pair<int, int>>> cache;
        
        for (size_t i=0; i<num.size(); ++i)
            for (size_t j=i+1; j<num.size(); ++j)
                cache[num[i]+num[j]].emplace_back(i, j);
        
        for (const auto &rp : cache) {
            auto found = cache.find(target - rp.first);
            if (found != cache.end())
                for (const auto &low : rp.second)
                    for (const auto &high : found->second)
                        if (low.second < high.first) ret.insert(vector<int>{num[low.first], num[low.second], num[high.first], num[high.second]});
        }
        
        return vector<vector<int>>(ret.cbegin(), ret.cend());
    }
};