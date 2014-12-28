#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, vector<int>{}, 0, ret);
        return ret;   
    }
    void dfs(const vector<int> &cdds, int target, vector<int> curr, size_t index, vector<vector<int>> &ret) {
        if (!target) {ret.push_back(curr); return; }
        for (auto i=index; i<cdds.size(); ++i)
            if (cdds[i] <= target) {
                curr.push_back(cdds[i]);
                dfs(cdds, target-cdds[i], curr, i, ret);
                curr.pop_back();
            } else break;
    }
};
