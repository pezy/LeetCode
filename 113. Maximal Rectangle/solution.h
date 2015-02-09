#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <algorithm>
using std::max; using std::min;

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
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int max_area = 0;
        vector<int> height(matrix[0].size(), 0);
        for (size_t i=0; i<matrix.size(); ++i) {
            for (size_t j=0; j<matrix[0].size(); ++j)
                if (matrix[i][j] == '0') height[j] = 0;
                else ++height[j];
            max_area = max(max_area, largestRectangleArea(height));
        }
        return max_area;
    }
};
