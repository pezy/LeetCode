#include <string>
using std::string;

#include <vector>
using std::vector;

#include <sstream>
using std::istringstream;

class Solution {
public:
    string simplifyPath(string path) {
        string ret, tmp;
        vector<string> stack;
        for ( istringstream iss(path); getline(iss, tmp, '/');  ) {
            if (tmp == ".." && !stack.empty()) stack.pop_back();
            else if (tmp == "." || tmp == ".." || tmp == "") continue;
            else stack.push_back(tmp);
        }
        for (auto str : stack) { ret += "/" + str; }
        return ret.empty() ? "/" : ret;
    }
};
