class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<3) return n;
        int size{1};
        for (int i=2; i<n; ++i)
            if (A[i] != A[size] || A[i] != A[size-1])
                A[++size] = A[i];
        return ++size;
    }
};
