ven a string **S** and s string **T**, count the number of distinct subsequences of **T** in **S**

这句话的实质是，统计 T 有多少个与 S 一样的子串。结合例子：

     S = "rabbbit", T = "rabbit"
            ^^^

将三个 b 任意删除一个，即可以称为一个独立的子串，并皆与 T 相同。故其结果为 3.

-----

说白了，这道题是问我们**有几种选择**，譬如例子中，是**删除第一个 b, 还是第二个？第三个？**。这让我们立刻可以回想起几天前做的一道题：[88. Edit Distance](../88. Edit Distance)，在那道题里，我们也是面对选择，是增加？删除？还是替换？

类似这种**多少种情况？多少种选择？** 的问题，我们就需要了解一下，这个问题是否可以分解成**重叠的子问题**，譬如说这道题，长度为 i 的 S, 长度为 j 的 T, 求有多少种 num(i, j) 解决方案，让 S -> T. 那么其子问题是什么？

很简单，让我求的是长度为 i 和 j, 那我看看 i-1 或 j-1 的情况，看看有没有重叠性？

为了说明的更加具体，我们用实例来分析：

     S: rab
     T: rabbit

如果 T 比 S 还长，这 T 便显然不是 S 的子串，故 `if(i < j) sum(i,j) = 0`

那反过来呢？直接让 T 小得可怜：

     S: rabbbit
     T: (null)

即 T 为空的情况，那么其子串也只有一种可能了，故 `sum(i,0) = 1`

上面两种极端情况分析过后，再来看几种正常情况：

     rabbbits             rabbbit
            ^                   ^
            S[i]    ==>         S[i-1]
     rabbit               rabbit
          ^                    ^
          T[j]                 T[j]

`if(S[i] != T[j]) sum(i,j) = sum(i-1, j)` 当 S 的末尾字符与 T 的末尾字符不同时，其结果与"去掉该字符无异”，这个自己非常显然了。

那如果相同呢？

     rabbbit               rabbbi
           ^                    ^
           S[i]      ==>        S[i-1]
     rabbit                rabbi
          ^                    ^
          T[j]                 T[j-1]

难道是这样的吗？如果相同，也无异？这让人有点怀疑，直接快进到关键的戏份呢？

     rabbb                 rabb
         ^                    ^
         S[i]        ==>      S[i-1]
     rabb                  rab
        ^                    ^
        T[j]                 T[j-1]
     (sum(i,j) == 3)       (sum(i,j) == 2)

看来明显不成立嘛，莫名其妙的解就少了一个。我们冷静一下，看看这个戏份到底有何不同之处，使我们上面的假设立刻失效。很快，就发现了一个诡异之处，即 S 如果去掉末尾的字符，竟然直接等于 T. 所以当我们将两者末尾的字符都去掉的时候，也同时去掉了一种情况！

加上这种情况，可以为我们组成最后一个公式：

     if(S[i] == T[j]) sum(i,j) = sum(i-1,j-1) + sum(i-1, j)
     //                                         ^
     //                                         如果去掉 S 的最后一个元素

------

总结一下这个问题的公式：

```cpp
          ___ 0
         |true
i < j ? -     ____ 1                ____ sum(i-1, j)
         |___|j==0                 |false
             |____ S[i] == T[j] ? -
                                   |____ sum(i-1, j) + sum(i-1,j-1)
```

DP 的问题最终都可以通过一个矩阵来表示解空间，此题也不外如是。此时我们有两个选择：

1. 按照上面的逻辑，i 为行，j 为列。外循环为迭代 S, 内循环为迭代 T.
2. 反其道而行之，j 为行，i 为列。外循环为迭代 T, 内循环为迭代 S.

若我们笃定存储整个矩阵，那么时间复杂度无区别，皆为 m*n. 时间复杂度也一致。但如果我们仅仅保留当前行的数据，因为 n < m, 所以选择 n 为空间复杂度，更为明智。即选择 1.

为了让大家理解整个矩阵的构成，对于上述两种选择，我都将矩阵列了出来，有识之士可以自己推演一下（都是针对例子：rabbbit 和 rabbit, x 代表 invalid, 即 S 或 T 为空时）

方案1:

       j| x 0 1 2 3 4 5
     ------------------
       x| 1 0 0 0 0 0 0 (null vs range rabbit)
     i=0| 1 1 0 0 0 0 0 (r vs range rabbit)
     i=1| 1 1 1 0 0 0 0 (ra vs range rabbit)
     i=2| 1 1 1 1 0 0 0 (rab vs range rabbit)
     i=3| 1 1 1 2 1 0 0 (rabb vs range rabbit)
     i=4| 1 1 1 3 3 0 0 (rabbb vs range rabbit)
     i=5| 1 1 1 3 3 3 0 (rabbbi vs range rabbit)
     i=6| 1 1 1 3 3 3 3 (rabbbit vs range rabbit)

方案2:

       i| x 0 1 2 3 4 5 6
     --------------------
       x| 1 1 1 1 1 1 1 1 (range rabbbit vs null)
     j=0| 0 1 1 1 1 1 1 1 (range rabbbit vs r)
     j=1| 0 0 1 1 1 1 1 1 (range rabbbit vs ra)
     j=2| 0 0 0 1 2 3 3 3 (range rabbbit vs rab)
     j=3| 0 0 0 0 1 3 3 3 (range rabbbit vs rabb)
     j=4| 0 0 0 0 0 0 3 3 (range rabbbit vs rabbi)
     j=5| 0 0 0 0 0 0 0 3 (range rabbbit vs rabbit)

这里，我还是按照咱们一致分析的思路选择了方案1，见到讨论里也有很多人选择方案2的。

无论选择哪种，都不太建议选择存储整个矩阵。因为在这道题里完全没有必要。
