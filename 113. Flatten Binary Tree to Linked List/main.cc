#include "solution.h"
#include <iostream>

int main()
{
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node4;
    node1.left = &node2;
    node1.right = &node3;
    node4.right = &node5;

    Solution s;
    s.flatten(&root);
    for (TreeNode *p = &root; p; p = p->right)
        std::cout << p->val << " ";
    std::cout << std::endl;
}
