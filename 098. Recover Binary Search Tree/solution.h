#include <cstddef>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void InorderTraversal(TreeNode *root, TreeNode **prev, TreeNode **first, TreeNode **second) {
        if (root == NULL) return;
        InorderTraversal(root->left, prev, first, second);
        if (*prev && (*prev)->val > root->val) {
            if (*first == NULL) *first = *prev;
            *second = root;
        }
        *prev = root;
        InorderTraversal(root->right, prev, first, second);
    }
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        InorderTraversal(root, &prev, &first, &second);
        if (first && second) std::swap(first->val, second->val);
    }
};
