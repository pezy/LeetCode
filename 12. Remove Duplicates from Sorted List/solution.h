struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    for (ListNode *cur = head; cur && cur->next; )
    {
      if (cur->val == cur->next->val) 
      {
        ListNode *del = cur->next;
        cur->next = del->next;
        delete del;
      }
      else cur = cur->next;
    }    
    return head;
  }
};
