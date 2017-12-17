#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <algorithm>
using std::max;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0, i = 0, size = height.size();
        for (stack<int> stk; i<size || !stk.empty(); )
            if (stk.empty() || (i != size && height[stk.top()] <= height[i])) stk.push(i++);
            else {
                int tp = stk.top(); stk.pop();
                max_area = max(max_area, height[tp] * (stk.empty() ? i : i-stk.top()-1));
            }
        return max_area;
    }
};
