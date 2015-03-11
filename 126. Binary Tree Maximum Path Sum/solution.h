#include <cstddef>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxPathSum(TreeNode *root, int &maxSum) {
        if (!root) return 0;
        int leftMax = std::max(0, maxPathSum(root->left, maxSum));
        int rightMax = std::max(0, maxPathSum(root->right, maxSum));
        maxSum = std::max(maxSum, leftMax+rightMax+root->val);
        return root->val + std::max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};
