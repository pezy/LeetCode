#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode pre_head(0);
        pre_head.next = head;
        for (ListNode *p = head; p; )
            if (p->next && p->val > p->next->val) {
                ListNode *i = &pre_head;
                while (!(i->next->val > p->next->val))
                    i = i->next;
                ListNode *pNode = p->next;
                p->next = pNode->next;
                pNode->next = i->next;
                i->next = pNode;
            } else { p = p->next; }
        return pre_head.next;
    }
};
