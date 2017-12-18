# 思路(C++)

此题需要好好读懂题意：**没有重复字符**的最长子字符串的**长度**。

首先，求的只是长度，那么一定有一个 trace 来边记录边比较(max)。
其次，没有重复字符几乎是唯一条件，那么检查重复显然用 k-v mapping.
最后，要考虑一次迭代过程中，如何度量这个长度。

----

设 substr 的起点为 start(s), 终点为 last(l). 每一次迭代，记录一张索引表。

    abcabcbb
    ^  ^
    s  l

|char|pos|
|:--:|:-:|
| a  | 0 |
| b  | 1 |
| c  | 2 |

上图所示，last 指向 `a`, 查询当前表可知，`a` 的位置记录在案，且 `pos >= start`. 故此刻诞生一个 substr. 长度为 `last - start`. s 更新位置为 `pos + 1`.

有：

```cpp
auto found = cache.find(s[last]);
if (found != cache.end() && found->second >= start) {
    ret = max(ret, last - start);
    start = found->second + 1;
}
cache[s[last]] = last;
```

注意最终还需要比较一次，返回 `max(ret, s.size() - start)`

## Python

思路与 C++ 完全一致。