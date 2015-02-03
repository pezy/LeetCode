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





