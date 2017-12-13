# 思路(C++)

这道题应该算是基本题了。我顺便复习了一下[二叉树的基本概念](http://en.wikipedia.org/wiki/Binary_tree)，并回顾了一下**深度优先遍历**和**广度优先遍历**两个重点知识。而这道题就是脱胎于前者的思想。

求 root 的最大深度，那么我就需要求出 left 的最大深度，以及 right 的最大深度。把 root 替换成 left 或 right 又会再重复上面的步骤。这显然是**递归**。

于是我们写个框架出来：

```cpp
int leftDepth = maxDepth(root->left);
int rightDepth = maxDepth(root->right);
return leftDepth > rightDepth ? leftDepth : rightDepth;
```

基本思路出来了，就需要考虑几个特殊情况：

1. 叶子节点返回什么？ 显然应该是1. (叶子节点的深度应该是1)
1. 如何判断是叶子节点？ `left == NULL, right == NULL`

好了，补充上述框架：

```cpp
if (root == NULL) return 0;
int leftDepth = maxDepth(root->left);
int rightDepth = maxDepth(root->right);
return leftDepth > rightDepth ? ++leftDepth : ++rightDepth; // 如果是叶子节点，leftDepth rightDepth都是0，返回1.
```

这基本就OK了。但看起来不够简洁啊。最后一步不就是求个最大值？用 STL 得了。

```cpp
if (root == NULL) return 0;
return std::max(maxDepth(root->left), maxDepth(root->right))+1;
```

这就是我的最后答案。

PS: C++ 11 更推荐使用 `nullptr` 来代替 `NULL` ，但是原数据结构中使用了 `NULL` ，这里只好妥协。

## Python

思路与 C++ 一致，本来想用迭代的方式写个不一样的，但写完觉得实在太啰嗦了，还是这个解法看起来简洁明了。
