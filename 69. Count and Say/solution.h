#include <string>
using std::string;

class Solution {
public:
    string countAndSay(int n) {
        string ret{"1"};
        for (int i=0; i<n-1; ++i) {
            string str;
            auto b = ret.cbegin();
            for (auto e=b; e != ret.cend(); ++e)
                if (*b != *e) { str += std::to_string(e-b) + *b; b = e; }
            ret = str + std::to_string(ret.cend()-b) + *b;
        }
        return ret;
    }
};
