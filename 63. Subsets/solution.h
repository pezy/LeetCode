#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> set(S.cbegin(), S.cend());
        std::sort(set.begin(), set.end());
        int size = pow(2, set.size());
        vector<vector<int>> retv(size);
        for (int i=0; i<size; ++i)
            for (decltype(set.size()) j=0; j<set.size(); ++j)
                if ((i >> j)&0x1) retv[i].push_back(set[j]);
        return retv;
    }
};
