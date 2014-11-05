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
        return root == NULL || (isBalanced(root->left) 
                             && isBalanced(root->right) 
                             && std::abs(treeHigh(root->left) - treeHigh(root->right)) <= 1);    
    }
private:  
    int treeHigh(TreeNode *node)
    {
        if (node == NULL) return 0;
        else return 1+std::max(treeHigh(node->left), treeHigh(node->right));
    }
};
