这道题应该如何着手？

首先我想到的是排序，因为如果所给数据如题目给出的例子一般有序，那非常容易：

     [1,3], [2,6], [8,10], [15,18]
        ^    ^
     [1,6], [8,10], [15,18]

只需迭代一遍，比较一下前一个 interval 的 end, 和下一个 interval 的 start 即可。

按照这个朴素的思路，我们飞快的写下如下代码：

```cpp
vector<Interval> ret;
std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
    return a.start < b.start;
});
for (const auto &interval : intervals) {
    if (!ret.empty() && interval.start <= ret.back().end)
        ret.back().end = std::max(interval.end, ret.back().end);
    else ret.push_back(interval);
}
return ret;
```

颤颤巍巍的提交了一下。。。

竟然发现 AC 了，而且效率颇高！！！

难道不是搞笑吗？这是 Hard 难度的题？我走错门了吧？
