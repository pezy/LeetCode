class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int size = 1;
        for (int i = 1; i != n; ++i)
            if (A[i-1] != A[i])
                A[size++] = A[i];
        return size;
    }
};
