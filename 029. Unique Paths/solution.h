#include <functional>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) std::swap(m, n);
        if (m < 2) return m;
        std::vector<int> steps(n, 1);
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)  
                steps[j] += steps[j-1];
        return steps[n-1];
    }
};
