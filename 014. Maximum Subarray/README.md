这道题我一看到，我就想到了我的最爱——**[贪心算法](http://zh.wikipedia.org/wiki/%E8%B4%AA%E5%BF%83%E6%B3%95)**，太典型了好么。
求拥有最大**和**的子序列，那么秉承贪心原则，假设初始解为A[0]，那么我增加一个元素(A[1])，我就需要考虑，我的利益是多了，还是损失了。
由于题意要求，子序列至少要连续，所以没可能跳过 A[1], 只有两个选择：

1. A[0] + A[1]
2. A[1]

说白了，就是，要么容纳新文化（改良派），要么重新开始（革命派）。哪一种可以带来最大利益，就选择哪一种。（因为人类社会也是连续的）

但这里，如果发生了革命，就会产生断链。把镜头拉远，从整条历史长河去看，每一条链子，哪一条最长呢？至少你得记录下巅峰的最大利益吧？

根据上述两条原则，我们写下了我们的算法：
```cpp
benefited = max(A[i], benefited + A[i]);
maxv = max(benefited, maxv);
```

聪明的你一定发现了，第一句条恰是**当权者的决策**，第二条恰是**历史学家的总结**。 横批：人类是贪婪的。

所以不要怪任何一方，从他们的立场看，都是最优解。局部最优能否导致整体最优呢？ 千年谜题。

------

题目比较基础，扯了点政治与历史。谁说计算机与人文不是密切相关的。。。

------

另外，该题下面说到 More practice， 提到要用分治法？我没什么思路，请明白者提点。

>If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle

咳咳咳， @Mooophy ，该出来了。。。

-----

@Mooophy 应约而出，给出了[代码](#8)，我根据其代码，尝试分析一下分治法的策略：

分治法的灵魂在于一个 **"分"** 字。对于这道题而言，求`A`的最大和子序列，可以给`A`来一刀：

    −2,1,−3,4,−1,2,1,−5,4
    left       |    right
           crossing

由于子序列连续，它必然属于上述划分中的某一种情况：

- 完全属于 left 部分
- 完全属于 right 部分
- 属于 crossing 部分（即跨越中点）

于是其核心代码如下：

```cpp
int maxSubArray(int A[], int l, int h) {
    if (l == h) return A[l]; // 仅有一个数
    int m = (l + h) / 2;     // 中点位置(划分点)
    return std::max({maxSubArray(A, l, m), maxSubArray(A, m+1, h), maxCrossing(A, l, m, h)});
}
```

是否非常的简洁呢？

下面问题集中在 `maxCrossing` 的策略，这个过程可以线性求出。即将其属于 `left` 范畴的 `sum` 与属于 `right` 范畴的 `sum` 加起来即可。

实现代码请见：[divide_conquer.h](divide_conquer.h)

这部分的详细思路可参考 CLRS 的第四章分治法的第一小节。
