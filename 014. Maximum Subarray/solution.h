#include <algorithm>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxv = A[0];
        for (int i=0, benefited = 0; i != n; ++i)
        {
            benefited = std::max(A[i], benefited + A[i]);
            maxv = std::max(maxv, benefited);
        }
        return maxv;
    }
};
