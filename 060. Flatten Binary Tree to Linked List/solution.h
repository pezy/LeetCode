#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root){
        for ( ; root; root = root->right)
            if (root->left) {
                TreeNode *end = root->left;
                while (end->right) end = end->right;
                end->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
    }
};
