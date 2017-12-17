#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    vector<string> ret;

    bool valid(const string &s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int num = std::stoi(s);
        return 0 <= num && num <= 255;
    }

    void restore(const string &origin, const string &ip, int part)
    {
        if (part == 0) {
            if (origin.empty()) ret.push_back(ip);
            return;
        }

        for (size_t i=1; i<4; ++i) {
            if (origin.size() < i) break;
            string section = origin.substr(0, i);
            if (valid(section)) {
                if (part != 1) section.append(".");
                restore(origin.substr(i), ip+section, part-1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() >= 4 && s.size() <= 12) restore(s, "", 4);
        return ret;
    }
};
