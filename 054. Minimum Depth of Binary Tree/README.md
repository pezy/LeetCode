拿到这道题, 先考虑一个问题:

```cpp
    1
   /
  2
```

这个二叉树, 最短路径是几? 没人会回答1吧? 只有一条路径, 而其长度显然是2, 那么返回值应该就是2了吧.

要求 root 的最短路径, 是否就是 root->left 和 root->right 的最短路径 + 1 呢? 即:

```cpp
return 1 + std::min(minDepth(root->left), minDepth(root->right));
```

这是一种常规情况, 即 root 既有左子树又有右子树的情况下. 如开始给出的案例, 显然就是不合适的.
左子树为1, 右子树却为0, 那么最后该返回 0+1 = 1? 显然就错了.

所以我们来列出几个特殊情况:

1. `root == null` 应该 return 0;
2. `root->left == null and root->right == null` 即遇到叶子, return 1;
3. `root->left and root->right` 即左右子树都存在, 常规情况下, 返回上面列出的式子.
4. `root->left and !root->right` 只有左子树, 如开始的案例, 应该只返回左子树的 minDepth(root->left);
5. 反之亦然.

好了, 将上述几种情况写成代码, 就 AC 了, Easy 难度的题, 最多5行. 而二叉树的题, 不用递归也是自找麻烦. 我就不麻烦了.
