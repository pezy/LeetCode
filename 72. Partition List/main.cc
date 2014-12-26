#include "solution.h"
#include <iostream>
#include <initializer_list>

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void printList(ListNode *head)
{
    for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;
}

void clearList(ListNode *head)
{
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

int main()
{
    Solution s;
    ListNode *ret = s.partition(create_linkedlist({1,4,3,2,5,2}), 3);
    //ListNode *ret = s.partition(create_linkedlist({3,1,2}), 3);
    printList(ret);
    clearList(ret);
}
