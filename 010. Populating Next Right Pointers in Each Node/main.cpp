#include <iostream>
#include "solution.h" 
#include <vector>
using vecIter = std::vector<int>::iterator;

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

TreeLinkNode *createBinaryTree(vecIter beg, vecIter end)
{
  std::vector<TreeLinkNode *> vec;
  for (vecIter it = beg; it != end; ++it)
    vec.push_back(new TreeLinkNode(*it));
  
  for (int i = 0, pos = 0; pos != vec.size()-1; ++i)
  {
    vec[i]->left = vec[++pos];
    vec[i]->right = vec[++pos];
  }
  return *vec.begin();
}

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
        root = root->left;
    }
}

int main(int argc, char** argv)
{
  std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  TreeLinkNode *root = createBinaryTree(vec.begin(), vec.end());
	
	Solution s;
	s.connect(root);
	print(root);
    
  return 0;
}
