#include <stack>
#include <vector>
using std::vector; using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        for (stack<TreeNode *> s; root || !s.empty(); )
            if (root)
            {
                s.push(root->right);
                ret.push_back(root->val);
                root = root->left;
            }
            else
            {
                root = s.top(); s.pop();
            }
        return ret;
    }
};
