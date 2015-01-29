class Solution {
public:
    int singleNumber(int A[], int n) {
        int r{0};
        for (int i = 0; i != n; ++i)
            r ^= A[i];
        return r; 
    }
};
