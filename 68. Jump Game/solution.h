#include <algorithm>

class Solution {
public:
    bool canJump(int A[], int n) {
    for (int i=0,max=0; i<=max; ++i)
        if((max = std::max(max, i+A[i])) >= n-1) return true;
    return false;
    }
};
