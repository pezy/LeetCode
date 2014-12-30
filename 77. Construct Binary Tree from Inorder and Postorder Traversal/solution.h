#include <cstddef>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    using vcIt = vector<int>::const_iterator;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }
    TreeNode *buildTree(vcIt inBeg, vcIt inEnd, vcIt postBeg, vcIt postEnd) {
        if (inBeg >= inEnd || postBeg >= postEnd) return NULL;
        TreeNode *root = new TreeNode(*prev(postEnd));
        auto inRoot = find(inBeg, inEnd, root->val);
        root->left = buildTree(inBeg, inRoot, postBeg, next(postBeg, inRoot-inBeg));
        root->right = buildTree(next(inRoot), inEnd, next(postBeg, inRoot-inBeg), prev(postEnd));
        return root;
    }
};
