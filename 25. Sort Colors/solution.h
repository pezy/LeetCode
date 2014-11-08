class Solution {
public:
    void sortColors(int A[], int n) {
        int r = 0, w = 0, b = 0;
        for (int i=0; i<n; ++i)
            switch (A[i]) {
                case 0: ++r; break;
                case 1: ++w; break;
                case 2: ++b; break;
            }
        for (int i=0; i<n; ++i) {
            if (i<r) A[i] = 0;
            else if (i<r+w) A[i] = 1;
            else A[i] = 2;
        }
    }
};
