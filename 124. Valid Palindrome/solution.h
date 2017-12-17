#include <string>
using std::string;
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        for (auto b=s.cbegin(), e=std::prev(s.cend()); b < e; ++b, --e) {
            while (!isalnum(*b)) ++b;
            while (!isalnum(*e)) --e;
            if (b < e && tolower(*b) != tolower(*e))
                return false;
        }
        return true;
    }
};
