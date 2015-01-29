#include <vector>
using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        for (int i = 0; i != 1<<n; ++i)
            vec.push_back(i/2^i);
        return vec;
    }
};
