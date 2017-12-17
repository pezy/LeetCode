#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool bFirstColZero = false;
        auto rows = matrix.size(), cols = matrix[0].size();
        
        for (decltype(rows) i=0; i<rows; ++i) {
            if (matrix[i][0] == 0) bFirstColZero = true;
            for (decltype(cols) j=1; j<cols; ++j)
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        }
        
        for (int i=rows-1; i>=0; --i) {
            for (int j=cols-1; j>0; --j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            if (bFirstColZero) matrix[i][0] = 0;
        }
    }
};
