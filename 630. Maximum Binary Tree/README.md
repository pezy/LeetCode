好久不来做题，为什么百忙之中来写这道题呢。。。

因为这被用来作为我司的面试题，而我却竟然还没做过。。。然后一看，果然比较基础，所以在这里写出来也无妨。

虽然被标记为 Medium，但实际是 easy 难度的。因为读题就能发现其递归特性。root... left... right...

所以如果面试遇到这个，你要笑开花了，用最直观的方式，按着题意写递归就好了。

首先将原函数拆解为递归形式：`constructMaximumBinaryTree(Iter beg, Iter end)`, 然后实现如下：

1. root = max(beg, end);
2. root.left = constructMaximumBinaryTree(beg, root_pos)
3. root.right = constructMaximumBinaryTree(root_pos + 1, end)

完。

对算法比较有追求的童鞋可以看下 [Cartesian tree](https://en.wikipedia.org/wiki/Cartesian_tree)，这道题的灵感应该是从这里来的。