#include <algorithm>
#include <vector>

using std::vector; using std::next_permutation;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        do {
            ret.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return ret;
    }
};
