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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *header = NULL;
        ListNode **p;
        for (p = &header; l1 && l2; p = &(*p)->next)
        {
            if (l1->val <= l2->val)
            {
                *p = l1;
                l1 = l1->next;
            }
            else
            {
                *p = l2;
                l2 = l2->next;
            }
        }
        *p = l1 ? l1 : l2;
        return header;
    }
};
