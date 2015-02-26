#include <string>
using std::string;

class Solution {
    void longestPalindrome(const string& s, int b, int e, int &start, int &last) {
        int len = s.size();
        while (b >= 0 && e < len && s[b] == s[e])
            --b, ++e;
        ++b, --e;
        if (e - b > last - start) {
            start = b;
            last = e;
        }
    }

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return s;
        int start = 0, last = 0;
        for (int i=0; i<len-1; ++i) {
            longestPalindrome(s, i, i, start, last);
            longestPalindrome(s, i, i+1, start, last);
        }
        return s.substr(start, last-start+1);
    }
};
