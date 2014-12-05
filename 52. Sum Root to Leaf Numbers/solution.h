#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
private:
    int sumNumbers(TreeNode *root, int sum)
    {
        if (!root) return 0;
        else if (!root->left && !root->right) return sum + root->val;
        else return sumNumbers(root->left, (root->val + sum) * 10) + sumNumbers(root->right, (root->val + sum) * 10);
    }
};
