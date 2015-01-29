/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head && head->next)
            for (ListNode *slower = head, *faster = head->next; faster && faster->next; slower = slower->next, faster = faster->next->next)
                if (slower == faster) return true;
        return false;
    }
};
