#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        bool carry{false};
        for (auto apos=a.size(), bpos=b.size(); apos || bpos || carry; ) {
            bool abit{apos && a[--apos] == '1'};
            bool bbit{bpos && b[--bpos] == '1'};
            ret = (abit ^ bbit ^ carry ? "1" : "0") + ret;
            carry = abit + bbit + carry >= 2;
        }
        return ret;
    }
};

