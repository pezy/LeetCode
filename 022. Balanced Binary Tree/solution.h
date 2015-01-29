/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <complex> 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        height(root);
        return bBalanced;    
    }
private:  
    int height(TreeNode *node)
    {
        if (node == NULL || !bBalanced) return 0;
        else
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            if (std::abs(leftHeight - rightHeight) > 1) bBalanced = false;
            return std::max(leftHeight, rightHeight) + 1;
        }
    }
    
    bool bBalanced = true;
};
