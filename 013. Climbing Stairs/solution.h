class Solution {
public:
    int climbStairs(int n) {
        if (n<0) return 0;
        else if (n<3) return n;
        int res = 0;
        for (int i = 0, a = 1, b = 2; i != n-2; ++i)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};
