#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::min;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        
        vector<vector<int>> A(n+1, vector<int>(m+1));
        for (int i=0; i<=m; ++i) A[0][i] = i;
        for (int i=0; i<=n; ++i) A[i][0] = i;
        
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                A[i][j] = min(min(A[i-1][j]+1, A[i][j-1]+1), A[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
        return A[n][m];
    }
};
