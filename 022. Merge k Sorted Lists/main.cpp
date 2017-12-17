#include "solution.h"
#include <iostream>

using namespace std;

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void clear(ListNode *head)
{
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next)
        cout << cur->val << "->";
    cout << "\b\b  " << endl;
}

int main()
{
    Solution s;
    vector<ListNode *> vec{
        create_linkedlist({1,3,5,7,9}),
        create_linkedlist({2,4,6,8,10}),
        create_linkedlist({0,11,12,13,14})
    };
    ListNode *ret = s.mergeKLists(vec);
    printList(ret);
    clear(ret);

    return 0;
}

