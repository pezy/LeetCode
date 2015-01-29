#include <iostream>
#include "solution.h"
#include <vector>

void print(TreeLinkNode *root)
{
    while (root)
    {
        std::cout << root->val;
        TreeLinkNode *cur = root->next;
        while (cur)
        {
            std::cout << "->" << cur->val;
            cur = cur->next;
        }
        std::cout << std::endl;
        while (root->next && !root->left) root = root->next;
        root = root->left;
    }
}

int main(int argc, char** argv)
{
  TreeLinkNode root(-2);
  TreeLinkNode node1(-9);
  TreeLinkNode node2(0);
  TreeLinkNode node3(3);
  TreeLinkNode node4(5);
  TreeLinkNode node5(-1);
  TreeLinkNode node6(9);
  TreeLinkNode node7(-6);
  TreeLinkNode node8(-1);
  TreeLinkNode node9(8);

  root.left = &node1;
  root.right = &node2;
  node1.left = &node3;
  node2.left = &node4;
  node2.right = &node5;
  node3.left = &node6;
  node5.left = &node7;
  node7.left = &node8;
  node7.right = &node9;

	Solution s;
	s.connect(&root);
	print(&root);

  return 0;
}
