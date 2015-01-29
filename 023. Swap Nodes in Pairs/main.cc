#include "solution.h"
#include <iostream>
#include <vector>
using vecIter = std::vector<int>::iterator;

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
    std::vector<int> vec = {1,2,3,4,5,6,7,8};
    Solution s;
    ListNode *ret = s.swapPairs(createLinkedList(vec.begin(), vec.end()));
    printAndClear(ret);
    
    return 0;
}
