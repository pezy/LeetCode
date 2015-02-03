#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t ret=0, start=0;
        unordered_map<char, size_t> cache = {{s.front(), 0}};
        for (size_t last=1; last < s.size(); ++last) {
            auto found = cache.find(s[last]);
            if (found != cache.end() && found->second >= start) {
                ret = max(ret, last - start);
                start = found->second + 1;
            }
            cache[s[last]] = last;
        }
        return max(ret, s.size()-start);
    }
};
