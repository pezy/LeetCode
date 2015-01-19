#include <cstddef> 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *pre = &preHead;
        bool isDuplicate = false;
        ListNode *p = head;
        while (p->next)
            if (p->val == p->next->val) {
                ListNode *next = p->next->next;
                delete p->next;
                p->next = next;
                isDuplicate = true;
            } else if (isDuplicate) {
                ListNode *next = p->next;
                delete p;
                p = next;
                pre->next = p;
                isDuplicate = false;
            } else {
                pre = p;
                p = p->next;
            }
        if (isDuplicate) {
            ListNode *next = p->next;
            delete p;
            pre->next = next;
        }
        return preHead.next;
    }
};
