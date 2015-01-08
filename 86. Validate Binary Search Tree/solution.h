#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, false, false, 0, 0);
    }
    bool isValidBST(TreeNode *root, bool left, bool right, int min, int max)
    {
        if (!root) return true;
        else if ((left && root->val <= min) || (right && root->val >= max)) return false;
        else return isValidBST(root->left, left, true, min, root->val) && isValidBST(root->right, true, right, root->val, max);
    }
};
