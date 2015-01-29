#include "solution.h"
#include <vector>
#include <iostream>
using std::vector; using std::cout; using std::endl;
using vecIter = vector<int>::iterator;

TreeNode *createBinaryTree(vecIter beg, vecIter end)
{
  std::vector<TreeNode *> vec;
  for (vecIter it = beg; it != end; ++it)
    vec.push_back(new TreeNode(*it));
  
  for (decltype(vec.size()) i = 0, pos = 0; pos != vec.size()-1; ++i)
  {
    vec[i]->left = vec[++pos];
    vec[i]->right = vec[++pos];
  }
  return *vec.begin();
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createBinaryTree(vec.begin(), vec.end());
    
    Solution s;
    cout << (s.isBalanced(root) ? "true" : "false") << endl;
    
    return 0;
} 
