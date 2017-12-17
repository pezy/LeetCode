class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n<0) return false;
        for (int l=0, r=n-1; l<=r; )
        {
            int m = (l+r) >> 1;
            if (target == A[m] || target == A[l] || target == A[r]) return true;
            else if ((A[l] < A[m] && target > A[l] && target < A[m]) || (A[l] > A[m] && target > A[l])) r = m-1;
            else if ((A[m] < A[r] && target > A[m] && target < A[r]) || (A[m] > A[r] && target < A[r])) l = m+1;
            else ++l, --r;
        }
        return false;
    }
};
