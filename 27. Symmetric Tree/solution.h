#include <cstddef>

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
        return check(root->left, root->right);
    }
private:
    bool check(TreeNode *lNode, TreeNode *rNode) {
        if (lNode && rNode)
            if (lNode->val != rNode->val) return false;
            else return check(lNode->left, rNode->right) && check(lNode->right, rNode->left);
        else if (lNode || rNode) return false;
        else return true;
    }
};
