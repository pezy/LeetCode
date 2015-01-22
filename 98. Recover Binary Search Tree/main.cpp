#include "solution.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node3.left = &node1;
    node3.right = &node5;
    node1.left = &node0;
    node1.right = &node6;
    node5.left = &node4;
    node5.right = &node2;

    Solution s;
    print_bfs(&node3);
    s.recoverTree(&node3);
    print_bfs(&node3);

    return 0;
}

