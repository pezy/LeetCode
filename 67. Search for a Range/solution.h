#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (A[0] == A[n-1] && A[0] == target) return vector<int>{0, n-1};
        vector<int> retv{-1, -1};
        for (int i=0, j=n-1; i<=j; ) {
            int mid = (i + j) >> 1;
            if (target == A[mid]) {retv[0] = retv[1] = mid; break;}
            else if (target < A[mid]) j = mid-1;
            else i = mid + 1;
        }
        while (retv[0]>0 && A[retv[0]-1] == target)
            --retv[0];
        while (retv[1]<n-1 && A[retv[1]+1] == target)
            ++retv[1];
        return retv;
    }
};
