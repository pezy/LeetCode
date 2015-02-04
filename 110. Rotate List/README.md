```cpp
                        |
1->2->3->4->5->NULL     | ListNode *slow = head, *fast = head;
^     ^                 | while (k--) {
slow  fast --->         |      if (fast == NULL) fast = head; // [1]
 |_____|                |      fast = fast->next;
    k                   | }
                        | if (fast == NULL) return head;
1->2->3->4->5->NULL     | while (fast->next) {
^     ^     ^           |      fast = fast->next;
head  slow  fast        |      slow = slow->next;
       |_____|          | }
          k             | List *new_head = slow->next;
                        | slow->next = NULL;
                        | fast->next = head;
                        | return new_head;
```

唯一要注意的在于:

[1]: 如果 k > linklist.size(n) 怎么办？

用示例来表示到底什么叫 rotate the list to the right by `k` places.

| k | origin | after |
|:-:|:------:|:-----:|
| 1 |0->1->2 |2->0->1|
| 2 |0->1->2 |1->2->0|
| 3 |0->1->2 |0->1->2|
| 4 |0->1->2 |2->0->1|

可以观察的出来，当 k > n 的时候，`k = k % n`.

参考资料：[what to do when k is greater than size of list ?](https://oj.leetcode.com/discuss/2353/what-to-do-when-k-is-greater-than-size-of-list)
