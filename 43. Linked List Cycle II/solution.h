#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head && head->next)
            for (ListNode *slow = head, *fast = head->next; fast && fast->next; slow = slow->next, fast = fast->next->next)
                if (slow == fast)
                    for (slow = slow->next; true; head = head->next, slow = slow->next)
                        if (slow == head) return slow;
        return NULL;
    }
};
