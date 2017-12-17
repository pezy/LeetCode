#include <functional>

class Solution {
public:
    int totalNQueens(int n) {
        int upperlim = (1 << n) - 1, sum = 0;
        std::function<void(int, int, int)> dfs = [&](int row, int l, int r)
        {
            if (row == upperlim) { ++sum; return; }
            for (int cur = upperlim & (~(row|l|r)), pos = 0; cur; dfs(row+pos, (l+pos)<<1, (r+pos)>>1))
            {
                pos = cur & (-cur);
                cur -= pos;
            }
        };
        dfs(0, 0, 0);
        return sum;
    }
};
