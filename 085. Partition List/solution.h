#include <cstddef> 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode pre_head(0), *pre = &pre_head;
        for (; head && head->val < x; head = head->next)
            pre = pre->next = head;
        for (ListNode *p=head, **pp=&head; p; p = *pp)
            if (p->val < x) {
                pre = pre->next = p;
                *pp = p->next;
            }
            else pp = &(*pp)->next;
        pre->next = head;
        return pre_head.next;
    }
};
