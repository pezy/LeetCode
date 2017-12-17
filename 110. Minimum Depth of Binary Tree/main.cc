#include "solution.h"
#include <iostream>

int main()
{
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node3.right = &node4;

    Solution s;
    std::cout << s.minDepth(&root) << std::endl;

    return 0;
}
