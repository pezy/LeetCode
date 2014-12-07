#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        else if (!root->left and !root->right) return 1;
        else if (root->left and root->right) return 1 + std::min(minDepth(root->left), minDepth(root->right));
        else return 1 + (root->left ? minDepth(root->left) : minDepth(root->right));
    }
};
