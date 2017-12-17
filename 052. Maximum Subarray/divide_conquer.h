#include <algorithm>
#include <climits>

class Solution {
    int maxCrossing(int A[], int l, int m, int h) {
        int left_max = INT_MIN, right_max = INT_MIN;
        for (int i=m, sum=0; i >= l; --i) {
            sum += A[i];
            if (left_max < sum) left_max = sum;
        }
        for (int i=m+1, sum=0; i <= h; ++i) {
            sum += A[i];
            if (right_max < sum) right_max = sum;
        }
        return left_max + right_max;
    }

    int maxSubArray(int A[], int l, int h) {
        if (l == h) return A[l];
        int m = (l + h) / 2;
        return std::max({maxSubArray(A, l, m), maxSubArray(A, m+1, h), maxCrossing(A, l, m, h)});
    }
public:
    int maxSubArray(int A[], int n) {
        return maxSubArray(A, 0, n-1);
    }
};
