#include <algorithm>

class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i=0, j=0; i<n; ++i)
            if (A[i] == 0) std::swap(A[i], A[j++]);
            else if (A[i] == 2) std::swap(A[i--], A[--n]);
    }
};
