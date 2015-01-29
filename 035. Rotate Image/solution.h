#include <algorithm>    // std::reverse
#include <vector>

using std::vector; using std::reverse; using std::swap;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (decltype(matrix.size()) i=0; i<matrix.size(); ++i)
            for (decltype(matrix.size()) j=i; j<matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
