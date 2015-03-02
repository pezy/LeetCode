#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    void moveNode(ListNode **destRef, ListNode **sourceRef) {
        ListNode *newNode = *sourceRef;
        *sourceRef = newNode->next;
        newNode->next = *destRef;
        *destRef = newNode;
    }
    ListNode *sortedMerge(ListNode *a, ListNode *b) {
        ListNode *ret = nullptr, **lastPtrRef = &ret;
        for (; a && b; lastPtrRef = &((*lastPtrRef)->next)) {
            if (a->val <= b->val) moveNode(lastPtrRef, &a);
            else moveNode(lastPtrRef, &b);
        }
        *lastPtrRef = a ? a : b;
        return ret;
    }
    void frontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef) {
        if (source == nullptr || source->next == nullptr) {*frontRef = source; *backRef = nullptr;}
        else {
            ListNode *slow = source, *fast = source->next;
            while (fast != nullptr) {
                fast = fast->next;
                if (fast != nullptr) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            *frontRef = source;
            *backRef = slow->next;
            slow->next = nullptr;
        }
    }
    void mergeSort(ListNode **headRef) {
        ListNode *head = *headRef, *front, *back;
        if (head == nullptr || head->next == nullptr) return;
        frontBackSplit(head, &front, &back);
        mergeSort(&front);
        mergeSort(&back);
        *headRef = sortedMerge(front, back);
    }
public:
    ListNode *sortList(ListNode *head) {
        mergeSort(&head);
        return head;
    }
};
