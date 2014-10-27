class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0; 
        if (n == 1) return n;
    
        int prevprev = 0, prev = 1;
        for (int i = 2; i <= n; ++i)
        {
            int curv = prevprev + prev; 
            prevprev = prev; 
            prev = curv;
        }
    
        return prevprev + prev;
    }
};
