#include <vector> 
#include <functional>

using std::vector; using std::function;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> retv;
        vector<int> vec(k);
        function<void(int, int, int)> combine = [&](int i, int n, int k) {
            for (int j=k-1; i>0; j ? combine(i, n, j) : retv.push_back(vec))
                vec[j] = i--;
        };
        combine(n,n,k);
        return retv;
    }
};
