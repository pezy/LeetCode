#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  std::vector<int> inorderTraversal(TreeNode *root)
  {
    std::vector<int> v;
    inorderTraversal(root, v);
    return v;
  }

  void inorderTraversal(TreeNode *root, std::vector<int> &v)
  {
    if (root == NULL) return;
    inorderTraversal(root->left, v);
    v.push_back(root->val);
    inorderTraversal(root->right, v);
  }
};
