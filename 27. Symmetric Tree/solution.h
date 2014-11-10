#include <cstddef>
#include <stack>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        TreeNode *lt = root->left, *rt = root->right;
        for (std::stack<TreeNode*> stack; !stack.empty() || (lt&&rt); ) {
            if (lt && rt) {
                if (lt->val != rt->val) return false;
                stack.push(lt->right);stack.push(rt->left);
                lt = lt->left; rt = rt->right;
            }
            else if (lt || rt) return false;
            else {
                lt = stack.top(); stack.pop();
                rt = stack.top(); stack.pop();
            }
        }
        if (lt || rt) return false;
        else return true;
    }
};
