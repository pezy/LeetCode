class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int size = 1;
        if (n == 0 || n == 1) return n;
        for (int j = 1, curv = A[0]; j != n; ++j)
        {
            if (curv != A[j])
            {
                A[size++] = A[j];
                curv = A[j];
            }
        }
        return size;
    }
};
