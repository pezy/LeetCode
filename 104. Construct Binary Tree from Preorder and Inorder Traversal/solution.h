#include <vector>
#include <cstddef>
#include <algorithm>

using std::vector; using std::next; using std::prev;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    using cIter = vector<int>::const_iterator;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }
    TreeNode *buildTree(cIter preBeg, cIter preEnd, cIter inBeg, cIter inEnd) {
        if (preBeg >= preEnd || inBeg >= inEnd) return NULL;
        TreeNode *root = new TreeNode(*preBeg);
        auto inRoot = std::find(inBeg, inEnd, root->val);
        root->left = buildTree(next(preBeg), next(preBeg, inRoot-inBeg+1), inBeg, inRoot);
        root->right = buildTree(next(preBeg, inRoot-inBeg+1), preEnd, next(inRoot), inEnd);
        return root;
    }
};