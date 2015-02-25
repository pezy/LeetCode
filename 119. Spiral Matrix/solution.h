#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        int mMax = matrix.size();
        int nMax = matrix[0].size();
        int mMin = 0, nMin = 0;
        ret.reserve(mMax*nMax);
        for (; nMin<mMax && nMin<nMax; --mMax, --nMax, ++mMin, ++nMin) {
            for (int i=nMin; i<nMax; ++i)
                ret.push_back(matrix[mMin][i]);
            for (int i=mMin+1; i<mMax; ++i)
                ret.push_back(matrix[i][nMax-1]);
            if (mMax-1 == mMin) break;
            for (int i=nMax-2; i>=nMin; --i)
                ret.push_back(matrix[mMax-1][i]);
            if (nMax-1 == nMin) break;
            for (int i=mMax-2; i>mMin; --i)
                ret.push_back(matrix[i][nMin]);
        }
        return ret;
    }
};
