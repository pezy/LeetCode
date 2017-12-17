#include <vector>
using std::vector; 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1, 0);
        vec[0] = 1;
        for (int i=0; i<=rowIndex; ++i)
            for (int j=i; j>0; --j)
                vec[j] += vec[j-1];
        return vec;
    }
};
