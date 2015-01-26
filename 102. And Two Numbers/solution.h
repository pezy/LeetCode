#include <cstddef>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        for (div_t sum{0, 0}; sum.quot || l1 || l2; tail = tail->next) {
            if (l1) { sum.quot += l1->val; l1 = l1->next; }
            if (l2) { sum.quot += l2->val; l2 = l2->next; }
            sum = div(sum.quot, 10);
            tail->next = new ListNode(sum.rem);
        }
        return dummy.next;
    }
};
