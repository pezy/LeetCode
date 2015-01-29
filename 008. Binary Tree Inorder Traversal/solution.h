#include <vector>
#include <stack>
using std::vector; using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        for (stack<TreeNode *> s; !s.empty() || root; )
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top(); s.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};
