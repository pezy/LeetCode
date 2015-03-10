#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }

    ListNode *shuffleMerge(ListNode *a, ListNode *b) {
        ListNode *ret = NULL, **lastRef = &ret;
        while (a && b) {
            moveNode(lastRef, &a);
            lastRef = &((*lastRef)->next);
            moveNode(lastRef, &b);
            lastRef = &((*lastRef)->next);
        }
        *lastRef = a ? a : b;
        return ret;
    }

    void moveNode(ListNode **destRef, ListNode **sourceRef) {
        ListNode *newNode = *sourceRef;
        *sourceRef = newNode->next;
        newNode->next = *destRef;
        *destRef = newNode;
    }

public:
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        ListNode *slow = head, *fast = head->next;
        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        ListNode *back = reverseList(slow->next);
        slow->next = NULL;
        head = shuffleMerge(head, back);
    }
};
