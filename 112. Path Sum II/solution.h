#include <vector>
#include <cstddef>
#include <stack>
#include <algorithm>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        pathSum(root, sum, path, ret);
        return ret;
    }
    void pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &ret) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) ret.push_back(path);
        if (root->left) pathSum(root->left, sum-root->val, path, ret);
        if (root->right) pathSum(root->right, sum-root->val, path, ret);
        path.pop_back();
    }
};
