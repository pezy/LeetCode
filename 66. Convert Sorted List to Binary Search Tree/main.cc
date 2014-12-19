#include "solution.h"
#include <initializer_list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>

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

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution s;
    TreeNode *ret = s.sortedListToBST(create_linkedlist({1,2,3,4,5,6,7,8,9}));
    print_bfs(ret);
}
