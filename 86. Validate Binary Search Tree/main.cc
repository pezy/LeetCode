#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    TreeNode root(4);
    TreeNode node1(1);
    TreeNode node2(7);
    TreeNode node3(5);
    TreeNode node4(9);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    std::cout << s.isValidBST(&root) << std::endl;
}
