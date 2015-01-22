可以结合一下 [86. Validate Binary Search Tree](../86. Validate Binary Search Tree), 至少要清楚 BST 的概念。

就本质而言，BST 的核心特质就是**有序**。何谓有序？最直接的方式就是将 BST 按照 Inorder 的遍历思想下落，落下来的序列是有序的。

3
/  \
1    5
/ \  / \
0  2 4   6

0 1234 5 6  -> ordered

------

回到这道题，让我们 recover 这个 BST, 是因为某一次的 swap 出了错，关键是要理解 swap 出了什么错。提到 two elements, 再结合上面温习的基础概念，可以推测出，这两个 elements 待在了不该待的位置。我们 recover 的目的便是将这两个放错地方的 elements 对调过来。

题目又说了，不能动 BST 的结构，那么所谓的对调，便是针对值的对调。所以大致可以分为两个步骤：

1. find two error elements.
2. swap two elements' values.

对于第二步，非常 easy, 我们有 `std::swap`. 但是对于第一条，我们该如何查找，首先就应该想到是 DFS.

在 [77. Construct Binary Tree from Inorder and Postorder Traversal](../77. Construct Binary Tree from Inorder and Postorder Traversal) 中我们曾总结，对于二叉树来说，DFS 有三种方式：

- 先序遍历（先根遍历）
- 中序遍历（中根遍历）
- 后续遍历（后根遍历）

我们这道题的目的是查出哪里违反了 BST 的次序，正如最开始所说，最直接的方式是通过中序遍历的方式查看序列是否有序。那么我们显然应该选择中序遍历的 DFS 方法。

写出最简单的中序遍历：

```cpp
void InorderTraversal(TreeNode *root)
{
    if (root == NULL) return;
    InorderTraversal(root->left);
    cout << root->val << " ";
    InorderTraversal(root->right);
}
```

然后，考虑我们的需求，要找到两个元素，而找的条件是次序不符，如何叫次序不符？**先遍历出来的元素 > 后遍历出来的元素**，即为不符。

显然，我们需要三个指针来协助：`first`, `second`, `prev`, 分别代表第一个元素，第二个元素，上一个元素。

当出现 `prev->val > root->val` 时，表示找到不符的元素。若是第一个，则为 first. 无论是不是，都将当前的 root 赋给 second, 因为可能会出现仅有两个节点的情况（仅仅遍历一次，second 无法获取应得的值）. 这部分逻辑为：

```cpp
if (first == NULL) first = prev;
second = root;
```

然后，便没有太多可说的了。总体来说，本题难度不大。
