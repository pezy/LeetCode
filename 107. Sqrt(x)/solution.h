class Solution {
public:
    int sqrt(int x) {
        int l = 1, r = x, ret = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (m <= x / m) { l = m+1; ret = m; }
            else r = m-1;
        }
        return ret;
    }
};
