该题的第一版本，我几乎没有抓住问题的本质，而是纠结于**卡特兰数**的公式。见[06. Unique Binary Search Trees](../06. Unique Binary Search Trees)

无论怎么说，我们对 BST 应该非常清晰的认识，我总结三句话描述它的特点：

1. 左小右大
2. 递归向下
3. 独一无二

第一个特点说的是，左子树若存在，则其所有节点值均小于根节点；而右子树若存在，则其所有节点值均大于根节点。

第二个特点指，该结构具备递归性，其左、右节点也皆为 BST

第三个特点指，no duplicate nodes. 不存在值相等的节点。

我们熟知的 std::map 和 std::set 一般实现为红黑树，而红黑树恰是 BST 的一种（优化版）。

-----

说完概念与本质，再来分析题意。参数是节点数，要求用 1 ~ n 来组建所有可能的 BST。

- 根据第一个特点，1 ~ n 每一个值都可以用来做**根节点**，所以应该有一次循环：`for(int i=1; i<n; ++i)`
- 根据第二个特点，可以递归的解决左、右子树。
- 无需考虑等于的情况。

结合以上三点，基本的思路就有了。1 ~ n个节点，若 m 为根节点，那么：

- 左子树 : 1 ~ m-1
- 右子树 : m+1 ~ n

但由于循环的需要，而我们的根又是从 1 开始的，于是可以将上述范围改为：

- 左子树 : 1 ~ m
- 右子树 : m+1 ~ n+1

可以看出是一个 `[)` 的区间。

而这种形式也决定了咱们递归函数的格式：

```cpp
vector<TreeNode *> generateTrees(int b, int e) // 起点与终点(终点不被包括)
{
    if (e-b<2) return vector<TreeNode *>{e-b ? new TreeNode(b) : NULL}; // 如果起点==终点，证明该树为空；如果仅有起点存在，则返回起点数组。
    vector<TreeNode *> retv; // 最终返回的 vector
    for (int i=b; i<e; ++i) // 迭代每一个可以成为根节点的值
    {
        vector<TreeNode *> retLeft = generateTrees(b, i); // 递归计算左子树
        vector<TreeNode *> retRight = generateTrees(i+1, e); // 递归计算右子树

        // 迭代拼接根节点与左子树右子树
        for (auto pL : retLeft)
            for (auto pR : retRight) {
                TreeNode *root = new TreeNode(i); // new 出根
                root->left = pL;
                root->right = pR;
                retv.push_back(root); // 存入 vector.
            }
    }
}
```

-----

效率还不错，排名靠前。84ms.
