真是怕什么来什么，又是一道二分查找。

为了增加乐趣，我这次采用了迭代器的方式，不过本质和数组形式差不多啦。(个人还是偏爱数组的形式，直观而简洁)

这题的关键在于它是有 pivot 的，而且是将 sorted array 经过 rotate 得来。那么它一定是由**两段有序数组组成**。

找最小， 还是找，所以先折半，i 在头， j 在尾， 注意，如果此刻 A[i] < A[j] 意味着什么？ 意味着从头到尾有序，那么它一定是未旋转的。这是此题的关键。

然后，再想， A[i] <= A[mid] 意味着什么？ 等于 A[j] <= A[i] <= A[mid] ，很显然，从 i 到 mid 都是有序的，且都比 A[j] 要大，所以这一段需要略过，让 i = mid+1;

反之，若 A[i] > A[mid]， 且此时 A[i] >= A[j]，那么显然， 从 i 开始的有序子数组还没到 mid 就遇到了 pivot. 那么 pivot 一定位于 i 与 mid 中间，故让 j = mid;

我很快实现了数组版本，而且一次性AC了，意犹未尽的改写成迭代器版本，迎合一下 @Mooophy 的口味，写完发现也不错，很简洁干净。

-----

这道题 AC 后，LeetCode 给我发了个通知，告诉我解锁了一个 [Solution](https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/), 这可是从未有过的体验。这个 Solution 的最后，还告诉我，更多内容更，请见[这本书](https://oj.leetcode.com/book/).

哇， LeetCode 竟然出书了。需要 15$，鉴于我还是一个屌丝，就先收藏算了。。。

-----

这个 Solution 的讲解比我透彻多了，截一幅图如下，表述数组 rotate 的过程：

![graph](https://cloud.githubusercontent.com/assets/1147451/5118947/b14f2458-70a4-11e4-8f64-464141db921c.png)

可以非常非常**显然**的发现：

- 没 rotate : AL < AR
- rotate 后 : AL > AR

截取 M1 折半：

- 若 AM1 > AR : 可知 [AL ... AM1] 大于 AR
- 反之        : 最小值一定在 [AM1 + 1 ... AR] 中间

截取 M2 折半：

- 若 M2 <= AR : 可知 [AM2+1 ... AR] 大于 AM2
- 反之        : 最小值一定在 [AL ... AM2] 中间

每一步舍弃一半，算法复杂度：O(log n).

-----

一图胜千言，此之谓也。
