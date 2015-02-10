这一阶段的 LeetCode 有一个明显的特点，就是在增加难度的同时，还紧密联系之前的 Easy 难度的题目。

昨天的两道姊妹题是如此，今天的链表题依旧如此。

这道题，显然是 [019. Merge Two Sorted Lists](../019. Merge Two Sorted Lists) 的升级版。

对于想复习基础的链表操作的童鞋，我推荐看看我的[这篇总结](http://segmentfault.com/blog/pezy/1190000002490878)。

-----

拿到问题，合并多个链表。而此刻，我们已经掌握了合并两个链表的方法。于是我们很自然的列出以下几种情况：

- lists.empty() : 返回 NULL
- lists.size() == 1 : 返回该链表
- lists.size() == 2 : 正好碰枪口，mergeTwoLists.
- lists.size() == 3 : 先合并后两个，在将其结果与第三个合并。
- lists.size() == 4 : 先两两合并，然后再将结果合并。
- ...

就没必要一直列下去了吧。

分而治之，是非常自然而然的思路，我们如果会造枪，但要的却是炮，我们将枪捆在一起，捆的无限多，便成了炮。

注意，为了更方便分治，我们将原题目的接口扩展为更通用的迭代器接口。

然后核心的语句是：

    return mergeTwoLists(mergeKLists(beg, beg + std::distance(beg, end)/2), mergeKLists(beg + std::distance(beg, end)/2, end));

提交，AC，离最快差了不过 4 ms.