#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;

    std::cout << s.maxPathSum(&root) << std::endl;
}
