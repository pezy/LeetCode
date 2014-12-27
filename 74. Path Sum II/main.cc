#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(8);
    TreeNode node3(11);
    TreeNode node4(13);
    TreeNode node5(4);
    TreeNode node6(7);
    TreeNode node7(2);
    TreeNode node8(5);
    TreeNode node9(1);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node3.left = &node6;
    node3.right = &node7;
    node2.left = &node4;
    node2.right = &node5;
    node5.left = &node8;
    node5.right = &node9;

    for (const auto &v : s.pathSum(&root, 22)) {
        for (auto i : v)
            std::cout << i << "->";
        std::cout << "\b\b  " << std::endl;
    }
}
