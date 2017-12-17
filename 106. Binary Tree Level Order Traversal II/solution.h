#include <vector>
using std::vector;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        levelOrderBottom(root, 0);
        return vector<vector<int> >(vec_.rbegin(), vec_.rend());
    }

private:
    void levelOrderBottom(TreeNode *root, int level) {
        if (root == NULL) return;
        if (vec_.size() == level) vec_.push_back({root->val});
        else vec_[level].push_back(root->val);
        levelOrderBottom(root->left, level+1);
        levelOrderBottom(root->right, level+1);
    }

private:
    vector<vector<int> > vec_;
};
