这道题本身没什么难度。和 [100. Copy List with Random Pointer](../100. Copy List with Random Pointer) 其实是一回事。

但这道题首次提出了 undirected graph 的串行化的表示方法，却让我想了半天。

说实话，如何将 undirected graph 用 LeetCode 的串行化方式打印出来，比这道题本身难得多。

若有心有成竹的朋友，可以在 [#4](../../../issues/4) 里试试。

-----

这道题本身的话，用 DFS 即可解决，模仿 100 题的解答，我们依然用一张 Hash 表来对照着拷贝。

其余就无需多说了，代码也非常短。效率倒是一般，中间水平。
