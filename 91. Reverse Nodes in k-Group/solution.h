#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next || k<2) return head;
        ListNode pre(0);
        pre.next = head;

        for (ListNode *front = &pre, *back = &pre; true; front = head, back = head) {
            for (int count = k; count > 0; --count)
                if (!(back = back->next)) return pre.next;

            for (head = front->next; front->next != back; ) {
                ListNode *next = front->next;
                front->next = next->next;
                next->next = back->next;
                back->next = next;
            }
        }
        return pre.next;
    }
};
