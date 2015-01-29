#include "solution.h"
#include <iostream>
#include <vector>
using vecIter = std::vector<int>::iterator;

TreeNode *createBinaryTree(vecIter beg, vecIter end)
{
    std::vector<TreeNode *> vec;
    for (vecIter it = beg; it != end; ++it)
        vec.push_back(new TreeNode(*it));
    
    for (int i = 0, pos = 0; pos != vec.size()-1; ++i)
    {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }
    return *vec.begin();
}

int main()
{
    std::vector<int> vec{1,2,2,3,4,4,3,5,6,7,8,8,7,6,5};
    Solution s;
    std::cout << s.isSymmetric(createBinaryTree(vec.begin(), vec.end())) << std::endl;
    return 0;
}




