#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode **del = &head, *iter = head;
        for (int i=0; i<n; ++i, iter = iter->next) ;
        for (; iter != NULL; del = &((*del)->next), iter = iter->next ) ;
        *del = (*del)->next;
        return head;
    }
};
