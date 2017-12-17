#include <string>
using std::string;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::sort;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>::iterator> cache;
        vector<string> ret;
        for (auto iter = strs.begin(); iter != strs.end(); ++iter) {
            string tmp_str(*iter);
            sort(tmp_str.begin(), tmp_str.end());
            auto found = cache.find(tmp_str);
            if (found == cache.end())
                cache[tmp_str] = iter;
            else {
                ret.push_back(*iter);
                if (found->second != strs.end()) {
                    ret.push_back(*found->second);
                    found->second = strs.end();
                }
            }
        }
        return ret;
    }
};
