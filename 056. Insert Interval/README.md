这道题仍然考察的是特殊的数据结构。

这个 `Interval` 本质上就是一个 `std::pair`.

最初的序列保证有序，那么查找 `newInterval` 将会很快（类似二分查找即可）。找首部的时候，根据 start，找尾部的时候，根据 end.

若 newInterval 的 start 落在了某个 interval 之间，那么修改 start, 并从该 interval 处开始删除。

同理 end 落在了某个 interval 之间，那么修改 end, 并从上面开始处一直删除到该 interval.

修改好 start 和 end, 并删除重复区域后，直接插入即可。

若没有落在任何 interval 之间，那么也是直接插入。

思路很简单，我偷懒直接用了 `std::lower_bound` 算法。
