#include <stack>

struct TreeLinkNode { 
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        while (root->left)
        {
            root->left->next = root->right;
            for (TreeLinkNode *cur = root; cur->next; cur = cur->next)
            {
                cur->right->next = cur->next->left;
                cur->next->left->next = cur->next->right;
            }
            root = root->left;
        }
    }
};
