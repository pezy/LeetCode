这道题难点是个障眼法。

例子给出的二叉树一点代表性也没，我来给一个，说明题意：

        1
       / \
      2   3
     / \   \
    4   5   6

我们列举一下，这里面有多少种可能的路径(限完整的路径)：

        2       1           1
       / \     / \         / \
      4   5   2   3       2   3
       (11)    \   \     /     \
                5   6   4       6
                (17)       (16)

显然，咱们应该返回中间那个 sum, 是 17.这结果是咱们肉眼看出来的，需进一步分析其规律性。

首先，右边两个来自同一棵“大树”，为何选择了 17 呢，显然是取最大值。

其次，左边那棵树，实际是根节点的左子树。同理我们还可以列出其右子树：

    3
     \
      6
    (9)

那么左子树和右子树若没有这个例子里面这样简单，也有分支呢？那么还是求其最大值即可。咦，这是否有种递归性？

这个例子还有一个盲点，即所有节点值皆为正数，会不会有负数？如果有负数，可能咱们不需要“完整的路径”。

更全局的看，如果某个子树的 max sum 是个负数，还不如没有。“没有”如何表达？是了，`sum == 0.`

好了，分析到这里，可以开始尝试写递归函数了：

```cpp
int maxPathSum(TreeNode *root, int &maxSum) {
    if (!root) return 0;
    int leftMax = std::max(0, maxPathSum(root->left, maxSum));
    int rightMax = std::max(0, maxPathSum(root->right, maxSum));
    maxSum = std::max(sum, root->val + leftMax + rightMax);
    return root->val + std::max(leftMax, rightMax);
}
```

好像很简单的样子。主函数中，将 `maxSum` 初始化为最小值：`INT_MIN` 即可。

提交试试，AC.
