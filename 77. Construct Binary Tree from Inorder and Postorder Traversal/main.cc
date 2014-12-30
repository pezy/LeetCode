#include "solution.h"
#include <iostream>
#include <queue>

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string> v;
    std::queue<TreeNode *> q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node) 
            v.push_back(std::to_string(node->val));
        else {
            v.push_back("#");
            continue;
        }
        q.push(node->left); 
        q.push(node->right);
    } while (!q.empty());

    auto found = std::find_if(v.rbegin(), v.rend(), [](const std::string &s){ return s != "#"; });
    v.erase(found.base(), v.end());
    for (const auto &s : v)
        std::cout << s << ",";
    std::cout << "\b " << std::endl; 
}

int main()
{
    Solution s;
    std::vector<int> inorder{7,4,2,8,5,1,6,9,3};
    std::vector<int> postorder{7,4,8,5,2,9,6,3,1};
    print_bfs(s.buildTree(inorder, postorder));
}
