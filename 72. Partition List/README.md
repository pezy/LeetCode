这道题我拖延了一天，原因一，是因为工作紧张，无暇顾及；原因二，便是想深入一点探究指针在链表中的妙用。

由于原因二，我这道题也给出了两个解法，看了 Discuss，貌似还没有人像我这样解，当然 lambda 那个解法倒是和一个人撞衫了，思路一致，但我的解法运用指针更加极致。(就是这么自信)

lambda 那个解法只用了 5 行，但表意晦涩，估计如果不是想了很久这道题，或是已经洞察这道题的本质的人，应该是难以看明白的。所以我给出的"官方"解法是另一个方案。

下面我重点表述常规解法的思路，该解法虽啰嗦，但效率颇高，如下图所示：

![qq 20141226102829](https://cloud.githubusercontent.com/assets/1147451/5555551/4c659fb0-8cef-11e4-8e18-f7abf83ea6e9.png)

题目里有两个重点条件：

- all nodes less than x come before nodes greater than or equal to x
- preserve the original relative order of the nodes

简单说，就是小于 x 的移到左边去，大于且等于 x 的移到右边去，左右两边保持原来的顺序。

保持顺序很重要，想用 swap 的童鞋，劝你算了吧。我的思路呢，也很自然，要分隔左右，那我迭代一次整个链表，将小于 x 的节点摘出来，剩下的不就是大于等于 x 的节点了吗？然后连接两个链表即可。

要摘出来，就要有地方放，可以申请一个额外的节点作为 head，然后之前的 head 就是剩下节点的头节点，两者一连，返回额外节点的 head 即可。时间复杂度为 O(N)，空间复杂度为 O(1)。

```cpp
ListNode pre_head(0), *pre = &pre_head; // 申请一个额外节点 pre_head, 并设一个指向它的指针
for (; head && head->val < x; head=head->next)  // 这一步，是为了让 head 指向剩余节点的头，小于 x 的部分，扔给 pre。
    pre = pre->next = head; // 从右向左的顺序，pre->next 指向 head, 然后 pre 后移。
for (ListNode *p=head; **pp=&head; p; p=*pp) // 固定了 head 之后，就可以用一个指针 p 来迭代后面的节点了，由于我们要对链表进行删减，所以还需要一个二级指针 pp.
    if (p->val < x) {
        pre = pre->next = p;
        *pp = p->next; // 跳过摘走的节点
    } else *pp = (*pp)->next; // 后移
pre->next = head;   // 连接两个链表
return pre_head.next;   // 返回额外节点后续的内容
```

-----

写完这个方案后，我觉得可以更加极端的运用二级指针，如申请两个空指针，以及它们的二级指针：
```cpp
ListNode *prev = NULL, *back = NULL, **pp = &prev; **pb = &back;
// 然后我的想法是，小于 x 的直接放到 prev， 其他的直接放到 back，然后连接 prev 和 back，由于 head 是指针传值，那么直接用它做迭代指针。
for (; head; ) {
    if (head->val < x) {
        *pp = head; // 二级指针直接将 NULL 改为了 head
        pp = &head->next; // 这相当于二级指针的后移，如 *pp = (*pp)->next; 或 pp = &(*pp)->next;
        head = *pp; // 这相当于 head 的后移，等同于： head = head->next;
    }
    else
        //... 同样的方式处理 pb
}
```

如果我要把 for 循环里的内容写成函数呢？ 如 lambda 函数？
```cpp
auto lambda = [&head](ListNode ***p){ // 以引用的方式传入 head, 参数为三级指针，为何？因为我们要对二级指针做修改。正如我们需要对一级指针修改时，使用到二级指针一样。
    // 下述内容根本不变，只是将 pp 换成了 *p 罢了
    **p = head;
    *p = &head->next;
    head = **p;
};
```

-----

好了，这道题随意用上述两个解法都可以高效 AC，看到有人 new 了两个新节点来存储左右链表，这就有点不合适了。

链表题，是非常考究对指针的理解的，想把指针搞透彻，就坚持多多训练自己链表操作。

这道题便是一个非常好的试金石~
