拿到这道题，我还是和往常一样瞬间写出了递归算法。递归的思想太伟大了，你仅需解决一个节点，那么下面的算法都可以重复利用。
而且能够做到思路清晰，代码简单，几乎连注释也不需要。

但很显然，我们不可能满足于用递归来解决这个问题。重新审视一下题意，注意两个Note:

1. You may only use constant extra space.
2. You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

第一个可以无视，我想几乎用不到什么容器，用一个额外的指针作为游标即可。第二个很关键，这是一颗完美的二叉树。这意味着什么？
意味着如果**某一层最左边的左节点存在，那么这一层都是存在的！**这少了多少判断？减少了多少难度？

所以第一层循环几乎确定：`root = root->left`. 判断条件也确定了：`while (root->left)`，**左节点是灵魂啊**，它的存在决定了我们的节奏。

很自然的，第二层循环应该是遍历各层的，为了不污染root一直在最左，我们需要额外用一个游标，假设是cur指针，即 `cur = cur->next`。
而判断条件恰恰是 `cur->next`。OK, 大体思路几乎确定。接下来就很简单了。

核心的步骤是：

```cpp
root->left->next = root->right; // 左子树内部连接
cur->right->next = cur->next->left; // 外部连接
cur->next->left->next = cur->next->right; // 右子树内部链接
```

提交，AC。

-----

已经做了十道题，我还没有参考过别人的答案，或是discuss。很庆幸，自己的基本功还算扎实，二叉树、链表竟然都没有白学，大学时期，
每堂课认认真真做的笔记，并没有随着大学时代的逝去而逝去。虽然我不擅长考试，也不聪明，但却属于那种掌握了学校所教授的全部必备知识的人。
LeetCode给了我自信，感谢它。
