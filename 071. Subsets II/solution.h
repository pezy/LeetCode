#include <vector>
#include <algorithm>
using std::vector; 

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret{{}};
        for (size_t i=0, b=0, e=0; i<S.size(); ++i)
            for (b=(i && S[i] == S[i-1] ? e : 0), e=ret.size(); b<e; ++b)
                ret.insert(ret.end(), ret[b])->push_back(S[i]);
        return ret;
    }
};
