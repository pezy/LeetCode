#include <iostream>
#include "solution.h" 

// Test Unit
//
//          1
//         / \
//        2   3
//       /\   /\
//      4 5  6  7
//     /\ /\ /\ /\
//    8 9A BC DE F
// ( A == 10 ...)

void print(TreeLinkNode *root)
{
    while (root)
    {
        std::cout << root->val;
        TreeLinkNode *cur = root->next;
        while (cur)
        {
            std::cout << cur->val;
            cur = cur->next;
        }
        root = root->left;
    }
}

int main(int argc, char** argv)
{
	TreeLinkNode root(1);
	TreeLinkNode node2(2);
	TreeLinkNode node3(3);
	TreeLinkNode node4(4);
	TreeLinkNode node5(5);
	TreeLinkNode node6(6);
	TreeLinkNode node7(7);
	TreeLinkNode node8(8);
	TreeLinkNode node9(9);
	TreeLinkNode nodeA(10);
	TreeLinkNode nodeB(11);
	TreeLinkNode nodeC(12);
	TreeLinkNode nodeD(13);
	TreeLinkNode nodeE(14);
	TreeLinkNode nodeF(15);
	
	root.left = &node2;
	root.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;
	node4.left = &node8;
	node4.right = &node9;
	node5.left = &nodeA;
	node5.right = &nodeB;
	node6.left = &nodeC;
	node6.right = &nodeD;
	node7.left = &nodeE;
	node7.right = &nodeF;
	
	Solution s;
	s.connect(&root);
	print(&root);
    
    return 0;
}
