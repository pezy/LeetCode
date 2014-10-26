#include <iostream>
#include "solution.h"

void print(ListNode *head)
{
  while (head)
  {
    std::cout << head->val;
    if (head->next) std::cout << "->";
    ListNode *del = head;
    head = head->next;
    delete del;
  }
  std::cout << std::endl;
}

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *head1 = new ListNode(1);
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(1);
  ListNode *node3 = new ListNode(2);
  ListNode *node4 = new ListNode(2);
  ListNode *node5 = new ListNode(3);
  ListNode *node6 = new ListNode(3);

  head->next = node1;
  node1->next = node3;

  head1->next = node2;
  node2->next = node4;
  node4->next = node5;
  node5->next = node6;

  Solution s;
  ListNode *res = s.deleteDuplicates(head);
  ListNode *res1 = s.deleteDuplicates(head1);

  print(res);
  print(res1);

  return 0;
}
