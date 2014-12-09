#include <algorithm>

using std::max;

class Solution {
public:
    int trap(int A[], int n) {
        if (n<3) return 0;
        int count{0};
        for (int i=0, j=n-1, maxI=A[i], maxJ=A[j]; i<j; maxI=max(maxI, A[i]), maxJ=max(maxJ, A[j]))
            if (maxI < maxJ) count += maxI - A[i++];
            else count += maxJ - A[j--];
        return count;
    }
};
