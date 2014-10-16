这道题应该算是基本题了。我顺便复习了一下二叉树的基本概念，并回顾了一下深度遍历和广度遍历两个重点知识。
而这道题就是脱胎于深度遍历的思想。

求root的最大深度，那么我就需要求出left的最大深度，以及right的最大深度。把root替换成left或right又会再继续上面的步骤。
这显然是递归。

于是我们写个框架出来：
```cpp
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return leftDepth > rightDepth ? leftDepth : rightDepth;
```

基本思路出来了，就需要考虑几个特殊情况：
1. 叶子节点返回什么？ 显然应该是1. (叶子节点的深度应该是1)
2. 如何判断是叶子节点？ left == NULL, right == NULL

好了，补充上述框架：
```cpp
  if (root == NULL) return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return leftDepth > rightDepth ? ++leftDepth : ++rightDepth; // 如果是叶子节点，leftDepth和rightDepth都是0，返回1.
```

这基本就OK了。但看起来不够简洁啊。最后一步不就是求个最大值？用STL得了。
```cpp
if (root == NULL) return 0;
return std::max(maxDepth(root->left), maxDepth(root->right))+1;
```

这就是我的最后答案。
PS: C++ 11 更推荐使用nullptr来代替NULL，但是原数据结构中使用了NULL，这里只好妥协。
