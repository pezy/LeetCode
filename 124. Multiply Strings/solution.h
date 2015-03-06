#include <string>
using std::string;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
        for (int i = num1.size()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                int sum = (ret[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                ret[i+j+1] = sum%10 + '0';
                carry = sum/10;
            }
            ret[i] += carry;
        }
        size_t pos = ret.find_first_not_of('0');
        if (pos != string::npos) return ret.substr(pos);
        else return "0";
    }
};
