#include <vector>
#include <set>
using std::vector;
#include <algorithm>
#include <functional>

class Solution {
public:
    void dfs(const vector<int> &num, vector<vector<int>> &ret, int target, vector<int> cur, size_t start) {
        if (target == 0) { ret.push_back(cur); return; }
        for (auto i = start; i < num.size(); ++i)
            if (i > start && num[i] == num[i-1]) continue;
            else if (num.at(i) <= target) {
                cur.push_back(num.at(i));
                dfs(num, ret, target - num.at(i), cur, i+1);
                cur.pop_back();
            } else break;
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ret;
        std::sort(num.begin(), num.end());
        dfs(num, ret, target, vector<int>{}, 0);
        return ret;
    }
};
