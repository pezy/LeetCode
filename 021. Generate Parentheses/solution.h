#include <vector>
#include <string>
#include <functional>

using std::string; using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        std::function<void(string, int, int)> addParenthesis = [&](string str, int ln, int rn) {
            if (ln == 0 && rn == 0) vec.push_back(str);
            if (ln > 0) addParenthesis(str+"(", ln-1, rn+1);
            if (rn > 0) addParenthesis(str+")", ln, rn-1);
        };
        addParenthesis("", n, 0);
        return vec;
    }
};
