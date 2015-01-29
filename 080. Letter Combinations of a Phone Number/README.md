这道题有几个要理解透的地方：

1. 0 和 1 的特殊性。这两个键并不对应字符，直接对应自身。
2. 字典显然应该预备好，长度固定，角标明显，可以考虑用 array.
3. 例子输入有误导性："Digit string "23""，其实输入的应该是 "23"，吃亏才知道。

综上，这题不算什么好题。

-----

结合 1 和 2 条，列出字典：

```cpp
std::array<string, 10> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
```

第一层循环，是迭代输入字符串:
```cpp
for (auto digit : digits) {
    // 将按键数字转为 map 的角标, 最简单的方式就是用 digit - '0'.
    for (auto c : map[digit - '0'])
        // 我们希望第一层迭代的字符称为后面的前缀，如"23"中，"abc"应分别称为"def"的前缀。
}
```

要实现前层成为后层的前缀，那么肯定需要三个 vector<string>。分别存储前后，以及最终组合。

而后层，实际上是当前层，当前意味着临时性。前层是必须要存储住的，最终就更不消说了。
所以可以考虑将前层与最终组合合并起来。那么用两个 vector<string> 搞定。

```cpp
vector<string> ret{""}; // 第一层没有前缀，所以留空。
for (auto digit : digits) {
    vector<string> tmp; // 当前层。
    for (auto c : map[digit - '0'])
        for (const auto &pre : ret) // 迭代前层，作为前缀
            tmp.push_back(pre + c); // 前缀 ＋ 当前层字符 = 当前最终字符串
    ret = tmp; // 将临时的当前字符串赋给最终字符串（也是前层）
}
```

AC 后，发现该算法效率最高，且人数最多，更加凸显这道题并无太多意义。。。
