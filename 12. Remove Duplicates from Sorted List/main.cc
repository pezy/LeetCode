#include <iostream>
#include <vector>
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
    vector<int> vec = {1,1,2};
    vector<int> vec1 = {1,1,2,3,3};
    
    ListNode *head = createLinkedList(vec.begin(), vec.end());
    ListNode *head1 = createLinkedList(vec1.begin(), vec1.end());
    
    Solution s;
    ListNode *res = s.deleteDuplicates(head);
    ListNode *res1 = s.deleteDuplicates(head1);
    
    printAndClear(res);
    printAndClear(res1);
    
    return 0;
}
