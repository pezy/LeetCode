首先，回顾一个基本的问题，单链表如何逆序？

     1->2->3->4->5
     ^
     root

想要逆序，最直接的想法，就是希望上图中的链表指向反过来。我们借用一个空指针 node 指向一个空节点:

     1->2->3->4->5 | ListNode* reverse(ListNode *root) {
     ^             |      ListNode *node = NULL;    
     root          | }
                   |
     NULL          |
     ^             |
     node          |

第一步，我们希望节点1从单链表中剥离，于是让其指向 node, 但我们不能因此而找不到链表索引，故需要一个额外的指针 next, 指向后续节点：

     2->3->4->5 | ListNode* reverse(ListNode *root) {
     ^          |      ListNode *node = NULL;   
     root       |      ListNode *next = root->next;     // next refer to 2
                |      root->next = node;               // root point to node
     1->NULL    |      node = root;                     // node refer to root(1)
     ^          |      root = next;                     // root refer to next(2)
     node       | }

几个简单的指针顶替，便将节点1反向的去指向了 node 节点。如法炮制的话，节点2, 节点3, 节点4, 节点5 都调转枪头，我们的目的便达到了。

```cpp
ListNode* reverse(ListNode *root) {
     ListNode *node = NULL;
     while (root) {
          ListNode *next = root->next;
          root->next = node;
          node = root;
          root = next;
     }
     return node;
}
```

-----

回到这道题，我们分析题目给出的例子：

     1->2->3->4->5, k=3
     => 3->2->1->4->5

对于这种连头指针都要被移动/替换的情况，果断创造一个 preHead(pre) 节点。另外，排除一些边界条件，如 k=0/k=1/head=NULL/head->next=NULL 这些情况。

     0->1->2->3->4->5 | if (head == NULL || head->next == NULL || k < 2) return head;
     ^                | ListNode pre(0);
     pre              | pre.next = head;

接下来我们起码要找到哪些节点要逆序，为了方便分析，使用 front 和 back 两个指针来指定逆序的范围。初始都指向 pre 节点，移动 back:

     0->1->2->3->4->5 | for (ListNode *front=&pre, *back=&pre; true; )
     ^        ^       |      for (int count=k; count>0; --count)
     front    back    |           if ((back = back->next) == NULL) return pre.next;

然后就要开始逆序了吗？不，我们先分析一下下一次的逆序范围应该从哪里开始:

     0->3->2->1->4->5 | // next iteration should start at 1
              ^       | // use head to refer it.
              head    | head = front->next;

确定了下一次的开头后，我们就可以进行逆序过程了，不比基本问题中全部的逆序，这里只是部分，肯定是无法直接用**指针顶替**了，那样不把自己搞死才怪。我们要想办法用指针来交换位置，以达到咱们逆序的目的。我们还是需要一个临时指针 next, 来协助我们。

      _(1)_           | while (front->next != back) {
     |     |          |      // next
     |     v          |      ListNode *next = front->next;
     0  1  2->3  4->5 |      // (1) front point to 2
     ^  ^     ^       |      front->next = next->next;
     f  n^    b  ^    |      // (2) next point to 4
        ||_(3)|  |    |      next->next = back->next;
        |________|    |      // (3) back point to 1
            (2)       |      back->next = next;
                      | }
     0->2->3->1->4->5 |
     ^  ^  ^          |
     f  n  b          |


如果我们死守着全逆序中指针顶替的方法，估计会吃不少苦头。局部范围内的处理，还是要以交换指针为主。


