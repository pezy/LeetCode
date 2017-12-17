#include <string> 
using std::string;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
        str.erase(str.find_last_not_of(' ')+1);
        if (str.empty()) return 0;
        auto found = str.find_last_of(' ');
        if (found == string::npos) return str.size();
        else return str.size() - found - 1;
    }
};
