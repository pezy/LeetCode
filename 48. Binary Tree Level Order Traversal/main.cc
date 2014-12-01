#include "solution.h"
#include <iostream>

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    
    Solution s;
    for (const auto &v : s.levelOrder(&root))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
