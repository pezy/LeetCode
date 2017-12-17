#include <string>
using std::string;
#include <algorithm>

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2.empty() || s1.size() != s2.size()) return false;
        else if (s1 == s2) return true;
        for(auto c : s1)
            if (s2.find_first_of(c) == string::npos) return false;
            else if (std::count(s1.cbegin(), s1.cend(), c) != std::count(s2.cbegin(), s2.cend(), c)) return false;
        for (size_t i=1; i<s1.size(); ++i)
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            else if (isScramble(s1.substr(0,i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) return true;
        return false;
    }
};
