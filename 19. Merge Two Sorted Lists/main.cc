#include <vector>
#include <iostream>
#include "solution.h"

using std::vector;
using vecIter = vector<int>::iterator;

ListNode *createLinkedList(vecIter beg, vecIter end)
{
    ListNode *head = beg == end ? NULL : new ListNode(*beg++);
    for (ListNode *cur = head; beg != end; cur = cur->next)
        cur->next = new ListNode(*beg++);
    return head;
}

void printAndClear(ListNode *head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        ListNode *del = head;
        head = head->next;
        delete del;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec1 = {1,3,5,7,9};
    std::vector<int> vec2 = {0,2,4,6,8};
    
    ListNode *l1 = createLinkedList(vec1.begin(), vec1.end());
    ListNode *l2 = createLinkedList(vec2.begin(), vec2.end());
    
    Solution s;
    printAndClear(s.mergeTwoLists(l1, l2));
    
    return 0;
}
