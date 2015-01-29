#include <vector>
#include <stack>
#include <cstddef>
using std::vector; using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> retv;
        TreeNode *last = NULL;
        for (stack<TreeNode*> stk; root || !stk.empty(); )
        {
            if (root)
            {
                stk.push(root);
                root = root->left;
            }
            else if (stk.top()->right && stk.top()->right != last)
            {
                root = stk.top()->right;
            }
            else
            {
                last = stk.top();
                retv.push_back(last->val); stk.pop();
            }
        }
        return retv;
    }
};
