#include <iostream>
#include <stack>
#include "solution.h"

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    for (std::stack<TreeNode *> s; !s.empty() || root; )
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top(); s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    return ret;
}

int main()
{
    vector<int> vec= {2,3,5,7,9,10,14,18};
    vector<int> vec1;
    Solution s;
    TreeNode *root = s.sortedArrayToBST(vec);
    for (auto i : inorderTraversal(root))
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
} 
