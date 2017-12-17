#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!(n-=m)) return head;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *pre = &preHead;
        while (--m) pre = pre->next;
        ListNode *first = pre->next;
        while (n--) {
            ListNode *p = first->next;
            first->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return preHead.next;
    }
};
