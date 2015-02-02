#include <string>
using std::string;
#include <numeric>

class Solution {
public:
    string getPermutation(int n, int k) {
        int table[10] = {1};
        for (int i=1; i<=9; ++i)
            table[i] = i*table[i-1];
        
        string dict(n, ' '), ret(dict);
        std::iota(dict.begin(), dict.end(), '1');
        
        for (int i=0; n>0; --n) {
            int pos = (k-1)/table[n-1];
            ret[i++] = dict[pos];
            dict.erase(dict.begin()+pos);
            k = k - pos * table[n-1];
        }
        return ret;
    }
    
};