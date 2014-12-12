#include <string>
#include <stack>

using std::string; using std::stack; 

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s)
            if (!stk.empty() && ((c == ')' && stk.top() == '(') || (c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '['))) stk.pop();
            else stk.push(c);
        return stk.empty();
    }
};
