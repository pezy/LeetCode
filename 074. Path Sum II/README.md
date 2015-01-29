这道题依旧继承上一道的思路，请见 [49. Path Sum](../49. Path Sum).

即，**倒叙递归**。

但我们需要在倒叙递归的过程中，记录整个路径，假设为 `vector<int> path;`:

设计递归函数，`pathSum`

```cpp
void pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &retv) {
    if (!root) return; // 边界条件为 root 为空
    path.push_back(root->val); // root 不为空，记录当前权值
    if (!root->left && !root->right && root->val == sum) retv.push_back(path); // 如是叶子，且路径总和等于 sum，那么收录该 path.
    // 若有左子树则递归左子树，若有右子树则递归右子树。
    if (root->left) pathSum(root->left, sum-root->val, path, retv);
    if (root->right) pathSum(root->right, sum-root->val, path, retv);
    // 该节点已走到，回溯至上一节点
    path.pop_back();
}
```

总体思路与上一道题一致，只不过那一道仅需判断 true or false，而这道题需要记录整个路径罢了。
