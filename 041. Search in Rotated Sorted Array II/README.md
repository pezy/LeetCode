又是恶心的折半查找题。

题目中说这道题是根据 Search in Rotated Sorted Array 的扩展，可是我竟根本没遇到过这一道题，查了下，还在后面。所以比较尴尬，这也许就是按照通过率做题的弊端吧。

但还好，我做过一个类似的，那道题是求最小值，难度还要再大一些呢。

正好是接受那道题的教训，这次我好好的画了三张图：

![1](https://cloud.githubusercontent.com/assets/1147451/5160514/f9a3f8b0-73c8-11e4-9ed8-e1e9c86a9edb.png)
![2](https://cloud.githubusercontent.com/assets/1147451/5160515/faf20cfc-73c8-11e4-8efd-abd308a42488.png)
![3](https://cloud.githubusercontent.com/assets/1147451/5160516/fc36f7a8-73c8-11e4-86ea-0b3c0f06b2a9.png)

可以看到，1是没经过旋转的，所以基本保持了有序状态；2和3都旋转了，只不过中点一个是最大值，一个是最小值。（mid我用红圈，首尾用的黑圈）

咱们的折半一定要将这三种情况想全面。

首先，如果要让 right = mid-1，即将范围缩小到左子数组，需要什么条件？

1. 对于图1，要 A[l] < target < A[m]
2. 对于图2和图3，只要 target > A[l]

如何区分这两种情况？

1. 对于图1和图2，A[l] < A[m]
2. 对于图3，A[l] > A[m]

有人说为啥不考虑相等的情况，答曰：太复杂，理不清，不如一开始就将相等的情况剔除：

    // 最开始
    if (target == A[m] || target == A[l] || target == A[r]) return ture;
    // 最后面
    ++l, ++r

这样就剔除了相等情况下的干扰。

若要将范围缩小到右子数组，就着眼于 A[r] 即可，思路与上面类似。不赘述了。
