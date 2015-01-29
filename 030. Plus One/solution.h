#include <vector>
using std::vector; 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
            if (++*iter < 10) break;
            else *iter = 0; 
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
