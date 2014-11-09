class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int k = m+n-1, i=m-1, j=n-1; k>=0; --k)
            if (i>=0 && j>=0) A[k] = A[i] > B[j] ? A[i--] : B[j--];
            else if (j>=0) A[k] = B[j--];        
    }
};
