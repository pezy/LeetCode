#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n,-1));
        for (int i=0, j=n; value != n*n; ++i, --j)
            spiralFilled(i, j, vec);
        return vec;
    }
private:
    void spiralFilled(int beg, int end, vector<vector<int> >& vec)
    {
        for (int i=beg, j=beg; true; )
        {
            if (vec[i][j] == -1) vec[i][j] = ++value;
            else break;
            if (i == beg && j != end-1) { ++j; continue; }
            if (j == end-1 && i != end-1) { ++i; continue; }
            if (i == end-1 && j != beg) { --j; continue; }
            if (j == beg && i != beg) { --i; continue; }
        }
    }
    
    int value{0};
};
