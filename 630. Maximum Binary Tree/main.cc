#include "solution.h"
#include <iostream>
#include <queue>
#include <algorithm>

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string> retv;
    std::queue<TreeNode *> q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node) 
            retv.push_back(std::to_string(node->val));
        else {
            retv.push_back("#");
            continue;
        }
        q.push(node->left); 
        q.push(node->right);
    } while (!q.empty());
    
    auto found = std::find_if(retv.rbegin(), retv.rend(), [](const std::string &s){ return s != "#"; });
    retv.erase(found.base(), retv.end());
    for (const auto &s : retv)
        std::cout << s << ",";
    std::cout << "\b " << std::endl; 
}

int main() 
{
  Solution s;
  std::vector<int> array{3,2,1,6,0,5};
  print_bfs(s.constructMaximumBinaryTree(array));
}
