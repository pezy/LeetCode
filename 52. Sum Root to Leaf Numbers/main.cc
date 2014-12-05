#include "solution.h"
#include <iostream>

int main()
{
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    
    root.left = &node1;
    root.right = &node2; 
    
    Solution s;
    std::cout << s.sumNumbers(&root) << std::endl;
    
    return 0;
}
