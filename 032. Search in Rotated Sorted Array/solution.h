class Solution {
public:
    int search(int A[], int n, int target) {
        for (int i = 0, j = n-1; i <= j; )
        {
            int m = (i + j) >> 1;
            if (target == A[m]) return m;
            else if ((A[i] <= target && target < A[m]) || (A[m] < A[i] && (target < A[m] || A[i] <= target))) j = m - 1;
            else if ((A[m] < target && target <= A[j]) || (A[j] < A[m] && (target <= A[j] || A[m] < target))) i = m + 1;
            else break;
        }
        return -1;
    }
};
