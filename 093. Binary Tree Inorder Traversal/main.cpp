#include <iostream>
#include "solution.h"
//#include "recursion.h"

using std::vector;

/// Test Unit
/// {1,2,3,#,#,4,#,#,5}
/* 
 *          1
 *         / \
 *        2   3
 *           /
 *          4
 *           \
 *            5
 */

int main(int argc, char** argv) {
  TreeNode root(1);
  TreeNode node2(2);
  TreeNode node3(3);
  TreeNode node4(4);
  TreeNode node5(5);
    
  root.left = &node2;
  root.right = &node3;
  node3.left = &node4;
  node4.right = &node5;
    
  Solution s;
  for (auto i : s.inorderTraversal(&root))
    std::cout << i << " ";
  std::cout << std::endl; 
    
  return 0;
}
