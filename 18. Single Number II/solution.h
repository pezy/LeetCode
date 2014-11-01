class Solution {
    public:
        int singleNumber(int A[], int n) {
            int low = 0;
            for (int i = 0, high = 0; i != n; ++i)
            {
                low ^= A[i] & ~high;
                high ^= A[i] & ~low;
            }
            return low;
        }
};
