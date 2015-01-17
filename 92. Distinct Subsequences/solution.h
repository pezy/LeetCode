#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = static_cast<int>(S.size());
        int n = static_cast<int>(T.size());
        if (m < n) return 0;
        vector<int> v(n+1, 0); v[0] = 1;
        for (int i=1; i<=m; ++i)
            for (int j=std::min(i, n)+1; j>0; --j)
                if(S[i-1] == T[j-1]) v[j] += v[j-1];
        
        return v.back();
    }
};