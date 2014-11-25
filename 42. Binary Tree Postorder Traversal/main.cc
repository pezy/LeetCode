#include "solution.h"
#include <iostream>

int main()
{
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    root.right = &node1;
    node1.left = &node2;
    
    Solution s;
    for (auto i : s.postorderTraversal(&root))
        std::cout << i << " ";
    std::cout << std::endl;    
    return 0;
} 
