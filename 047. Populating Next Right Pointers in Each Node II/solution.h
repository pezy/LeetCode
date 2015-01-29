struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    while (root and (root->left or root->right)) {
      if (root->left and root->right)
        root->left->next = root->right;
      for (TreeLinkNode *cur = root, *find = root->next; find; find = find->next) {
        if (!find->left and !find->right) continue;
        if (find->left and find->right)
          find->left->next = find->right;
          (cur->right ? cur->right->next : cur->left->next) = find->left ? find->left : find->right;
          cur = find;
      }
      root = root->left ? root->left : root->right;
      while (root->next && !root->left and !root->right) root = root->next;
    }
  }
};
