#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode *slow = head, *fast = head;
        while (k--) {
            if (fast == NULL) fast = head;
            fast = fast->next;
        }
        if (fast == NULL) return head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *new_head = slow->next;
        slow->next = NULL;
        fast->next = head;
        return new_head;
    }
};
