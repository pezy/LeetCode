这道题的题意很好理解。

给你一堆数字：

    25525511135

让你分割成符合要求的形式：

    255.255.11.135
    255.255.111.35


那么很自然的，首先考虑的是，什么叫符合要求。

IPV4的地址有以下几个特点：

1. 必须 4 段
2. 每一段是 0 ~ 255 之间

作为字符串，可能会出现 010 的情况，必须避免。故再加一条

3) 长度大于 1 的子段，不能以 0 开头。

可以看到，三条规定里，后两条都是针对分割后的每一段而言的。我们写一个函数来验证合法性：

```cpp
bool valid(const string &s) {
    if (s.size() > 1 && s[0] == '0') return false;
    int num = std::stoi(s);
    return 0 <= num && num <= 255;
}
```

假定以下情况：

    255. | 25511135
    ^      ^
    ip     origin string.

在 0 ~ 255 中间，也意味着子段的长度只可能是 1、2、3，我们在试探的时候仅需试探三次，写成循环：

    255
    ^
    section: 2, 25, 255

对于第一条，我们设定只能有 4 part, 每一次尝试都减 1.

```cpp
for (size_t i=1; i<4; ++i) {
    if (origin.size() < i) break; // 如果分了三段，最后一段不够长，stop
    string  section = origin.substr(0, i); // 可能的子串
    if (valid(section)) {
        if (part != 1) section.append("."); // 除了最后一段，每一段后面用 `.` 分隔
        dfs(origin.substr(i), ip+section, part-1);
    }

}
```

这明显是一个 DFS，那么递归必然有其退出条件。这里便是 `part == 0` 的情况。

```cpp
if (part == 0) {
    if (origin.empty()) ret.push_back(ip); // 最后一段，恰好分割完，入兜
    return; // 其他情况都不是我们想要的
}
```

总体来说，是比较简单的 DFS 方案。AC
