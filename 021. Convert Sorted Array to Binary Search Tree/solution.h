/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <vector>
#include <cstddef>
using std::vector;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
    
    TreeNode *sortedArrayToBST(vector<int>::iterator beg, vector<int>::iterator end)
    {
        if (beg == end) return NULL;
        auto mid = beg + (end - beg)/2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(beg, mid);
        root->right = sortedArrayToBST(std::next(mid), end);
        return root;
    }
};
