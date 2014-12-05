这道题没啥好说的，深度优先遍历。非常直观，另，劝君不要尝试非递归算法，给自己找麻烦，记录层数相当繁琐。

-----

我的解法超级简单, 只有寥寥几行代码，但思考却是一个循序渐进的过程:

这道题的难点在于，它要将一条路线上所有节点组成一个数字，这是一个很大的屏障，我们先试着不去想这个限制，假设我们就是要累加所有节点的数字：

```cpp
sumNumbers(root) = root->val + sumNumbers(root->left) + sumNumbers(root->right);
```

非常显然吧？好，我们将其补成一个完整的递归：

```cpp
int sumNumbers(TreeNode *root)
{
    if (!root) return 0;
    return root->val + sumNumbers(root->left) + sumNumbers(root->right);
}
```

这显然是一种从上至下的递归方式，如果我们要按题意来，有一个显然的事实：**每一个深度有多少层，其根节点就需要乘多少个10，可递推至其余节点。**

从上到下的递归，天然屏蔽了层数，我们逆向思维，如果从下到上呢？还是不考虑题目的限制，仅仅是累加，但我们增加一个参数 sum，记录上面路径累计的和。

```cpp
int sumNumbers(TreeNode *root, int sum)
{
    if (!root) return 0;
    else if (!root->left && !root->right) return sum + root->val;    // 单独处理叶子节点
    else return sumNumbers(root->left, sum + root->val) + sumNumbers(root->right, sum + root->val);
}
```

同样的事，换了一种思路，看似复杂了不少，从下往上，就需要了解**下限如何处理**，这里就是针对叶子节点的处理。很显然，叶子节点，应该返回整个深度的和，即 `root->val + sum`。

好了，到这一步，也没难到哪里去，我们总算可以进入正题，开始考虑题意。由于现在是从下往上，所以不再是考虑多少个10，而是考虑一个10的问题，具体看，一个叶子节点：

如果是组成一个数字，那么一定是： **到达这个叶子节点积累的和 (sum) * 10 + 叶子节点的 val.** 即：

```cpp
int sumNumbers(TreeNode *root, int sum)
{
    if (!root) return 0;
    else if (!root->left && !root->right) return sum + root->val;    // 单独处理叶子节点，这里的sum已经乘过10了。
    else return sumNumbers(root->left, (sum + root->val)*10) + sumNumbers(root->right, (sum + root->val)*10);
}
```

答案呼之欲出了吧，注意**上面虽然用叶子节点举例，但乘10是每一次递归都要做的事**
