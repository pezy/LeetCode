#include <algorithm>

class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        for (int i = 0; i < n;)
        {
            if (A[i] == elem) std::swap(A[i], A[--n]);
            else ++i;
        }
        return n;
    }
};
