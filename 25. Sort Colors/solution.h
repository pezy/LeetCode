#include <algorithm>

class Solution {
public:
    void sortColors(int A[], int n) {
        int pos = 0;
        for (int i=0; i != n;)
            if (A[pos]==0) i = ++pos;
            else if (A[i]==0) std::swap(A[pos], A[i]);
            else ++i;
        for (int i=pos; i != n; )
            if (A[pos]==1) i = ++pos;
            else if (A[i]==1) std::swap(A[pos], A[i]);
            else ++i;
    }
};
