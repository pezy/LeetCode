#include <vector>
#include <deque>
#include <cstddef>

using std::vector; using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> retv;
        if (root)
        {
            deque<TreeNode*> q{root}; 
            while (!q.empty())
            {
                vector<int> v;
                for (decltype(q.size()) i=0, n=q.size(); i!=n; ++i)
                {
                    TreeNode *node = q.front(); q.pop_front();
                    v.push_back(node->val);
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                }
                retv.push_back(v);
            }
        }
        return retv;
    }
};
