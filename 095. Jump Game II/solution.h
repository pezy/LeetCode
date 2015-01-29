#include <algorithm>

class Solution {
public:
    int jump(int A[], int n) {
        int step = 0, max = 0;
        for (int i=0, tmpMax=0; i<=max && i<n-1; ++i) {
            tmpMax = std::max(tmpMax, A[i]+i);
            if (i == max) { max = tmpMax; ++step; }
        }
        return max >= (n-1) ? step : -1;
    }
};

