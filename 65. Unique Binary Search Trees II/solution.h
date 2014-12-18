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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n+1);
    }
    vector<TreeNode *> generateTrees(int b, int e) {
        if (e-b < 2) return vector<TreeNode *>{e-b ? new TreeNode(b) : NULL};
        vector<TreeNode *> retv;
        for (int i=b; i<e; ++i) {
            vector<TreeNode *> retLeft = generateTrees(b, i);
            vector<TreeNode *> retRight = generateTrees(i+1, e);
            for (auto pL : retLeft)
                for (auto pR : retRight) {
                    TreeNode *root = new TreeNode(i);
                    root->left = pL;
                    root->right = pR;
                    retv.push_back(root);
                }
        }
        return retv;
    }    
};
