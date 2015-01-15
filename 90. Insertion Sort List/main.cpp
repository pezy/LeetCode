#include "solution.h"
#include <iostream>

using namespace std;

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
    ListNode *head = s.insertionSortList(create_linkedlist({3,7,4,9,5,2,6,1}));
    for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;

    return 0;
}

