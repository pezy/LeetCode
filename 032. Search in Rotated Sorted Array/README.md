还记得那道恶心的同类题吗？[41. Search in Rotated Sorted Array II](../41. Search in Rotated Sorted Array II)

两道题唯一的区别在于，数值是否可以重复。看起来，没有重复项的可能比较简单一些。其实，都一样恶心。

上次花了三幅图来讲解，这次做的时候，又有了更深的领悟，觉得那三幅图并不够清晰，于是我又画了三幅：

![1](https://cloud.githubusercontent.com/assets/1147451/5388239/4e904bb0-8122-11e4-9cf8-d2ed4c4925ef.png)
![2](https://cloud.githubusercontent.com/assets/1147451/5388238/4e8d1bc0-8122-11e4-9565-577cf11d0a23.png)
![3](https://cloud.githubusercontent.com/assets/1147451/5388237/4e8cec90-8122-11e4-8947-14f51de84947.png)

分别代表了可能的三种情况。

重点分析一下循环内部的判断情况：

1. `if (target == A[m]) return m;` // 这个是我们的终极目标，折半查找的终结。
2. 如果不是上面那种情况，我们显然需要两种不同的策略：
    1. 往左移动，`j = m - 1;`
        1. 图1中，target 落在了第1段。 `A[i] <= target < A[m]`
        2. 图2中，target 落在了2，或3段。 `A[m] < A[i] and (target >= A[i] or target < A[m])`
        3. 图3中，target 落在了第1段。 `A[i] <= target < A[m]`
    2. 往右移动，`i = m + 1;`
        1. 图1中，target 落在了第2段。 `A[m] < target <= A[j]`
        2. 图2中，target 落在了第1端。 `A[m] < target <= A[j]`
        3. 图3中，target 落在了2，或3段。 `A[m] > A[j] and (target > A[m] or target <= A[j])`

这样我们就将全部可能的**有效**，情况分析全了，如果都不满足怎么办？ 直接 break 出循环，不送。

可能有的疑惑在于判断落在2，或3段的情况。

为什么我一定要强调 `A[m] < A[i]` 或 `A[j] < A[m]`？

那是因为我需要和其他两种情况作区分，从图上很容易看出他们的终极区别。
