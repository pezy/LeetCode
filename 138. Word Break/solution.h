#include <string>
using std::string;
#include <unordered_set>
using std::unordered_set;
#include <vector>

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.find(s) != dict.end()) return true;
        std::vector<string::const_iterator> cache{s.cbegin()};
        for (auto subEnd = s.cbegin(); subEnd != s.cend(); ++subEnd)
            for (auto subBeg : cache)
                if (subBeg < subEnd && dict.find(string(subBeg, subEnd)) != dict.end()) {
                    if (dict.find(string(subEnd, s.cend())) != dict.end()) return true;
                    cache.push_back(subEnd); break;
                }
        return false;
    }
};
