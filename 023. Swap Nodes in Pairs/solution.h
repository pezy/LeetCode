/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef> 
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        for (ListNode *p1 = newHead, *p2 = head; p2 && p2->next; p1 = p2, p2 = p2->next)
        {
            p1->next = p2->next;
            p2->next = p1->next->next;
            p1->next->next = p2;
        }
        return newHead->next;
    }
};
