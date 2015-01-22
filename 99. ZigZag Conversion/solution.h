#include <string>
using std::string;
#include <vector>
#include <numeric>


class Solution {
public:
    string convert(string s, int nRows) {
        if (s.empty() || nRows < 2) return s;
        std::vector<string> ret(nRows);
        for (size_t i=0; i<s.size(); ++i) {
            int m = i % (nRows-1), n = i / (nRows-1);
            (n & 0x1 ? ret[nRows-m-1] : ret[m]) += s[i];
        }
        return std::accumulate(ret.cbegin(), ret.cend(), string());
    }
};
