#include <vector>
#include <algorithm>

using std::vector; using std::find; using std::next; using std::prev;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), high = m*n-1;
        for (int low = 0, mid; low < high; )
        {
            mid = (low+high-1) >> 1;
            if (target > matrix[mid/n][mid%n]) low = mid + 1;
            else high = mid;
        }
        return matrix[high/n][high%n] == target;
    }
};
