#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        for (decltype(grid.size()) i=0; i<grid.size(); ++i)
            for (decltype(grid[0].size()) j=0; j<grid[0].size(); ++j)
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
        return grid.back().back();
    }
};
