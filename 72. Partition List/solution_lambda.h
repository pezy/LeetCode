#include <cstddef> 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *prev = NULL, *back = NULL, **pp = &prev, **pb = &back;
        for ( ; head; [&head](ListNode ***p){
            **p = head; *p = &head->next; head = **p;
        }(head->val < x ? &pp : &pb));
        *pp = back; *pb = NULL;
        return prev;
    }
};
