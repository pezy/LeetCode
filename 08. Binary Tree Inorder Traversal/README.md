这题考察中序遍历，属于基本题了。

我从未刻意的记忆这些经典的算法如何写，我习惯记忆的是逻辑。中序遍历，说白了，就是**先左，然后中， 最后右**。
那么递归解法几乎呼之欲出了：

```cpp
vector<int> ret;
if (root)
{
    if (root->left) ret = inorderTraversal(root->left);
    ret.push_back(root->val);
    if (root->right)
    {
        vector<int> vec = inorderTraversal(root->right);
        ret.insert(ret.end(), vec.begin(), vec.end());
    }
}

return ret;
```

其实用上述这段程序，提交LeetCode， 你也会收到一个AC，只不过等待时间稍稍长了点。

-----

经 @Mooophy 指点, 这个递归其实并不直观, 他提供了一个更直观简洁的写法(略有改动), 我看了后拍案叫绝.
```cpp
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> v;
    inorderTraversal(root, v);
    return v;
}

void inorderTraversal(TreeNode *root, std::vector<int> &v)
{
    if (root == NULL) return;
    inorderTraversal(root->left, v);
    v.push_back(root->val);
    inorderTraversal(root->right, v);
}
```
他巧妙(或者说更自然的)多用了一个函数, 使得递归过程, 更加的漂亮. 避免了上面我所使用的无奈之举 -- insert. 这种思路要借鉴.

-----

咱们的追求不能仅仅于此对吧。非递归解法才是挑战。手动的记录节点，需要一个栈来帮我们，我用STL我自豪，于是我请来了 std::stack， 然后
几乎还是参考上面递归的思路。只不过入栈的顺序是先root，然后left，等到right，则先出left, 然后root, 最后再出right。 这个是核心思路。

要考虑的重点在于： 什么时候遍历结束？

两个条件： root == NULL 且 stack.empty() 同时成立。**前者意味着这个分支走到了头，后者意味着没有分支可走。**

换句话说，上述两个条件有一个成立，我们就要接着遍历。遍历时，root 存在，则压栈，看left；root 不存在，则出栈（回头路），看right。

思路就很清楚了吧？
