Question is Longest Palindromic Substring.

假设 S(i, j) 为问题的解，即从位置 `i` 到 `j` 的字符串是 Longest Palindromic Substring of the string.

我们从最简单的字符串来想：

    a

单字符本身是否是回文？是。即 S(i, i)

    a a

两个相同字符是否组成回文？是。即 S(i, i+1) when `s[i] == s[i+1]`.

    b a a b

为上面的回文字符串首尾增加一个相同的字符 `b`, 组成了回文，即 S(i, j) when S(i+1, j-1) and `s[i] == s[j]`.

**由于我们持续在首尾增加字符，对于单字符，则长度一直为奇数；对于双字符，则长度一直为偶数。所以要涵盖所有情况，需要分别验证这两种情况。**

好了，分析到这里基本可以明白回文的规律所在了。

要求的是长度，那么我们记 Longest Palindromic Substring 为 longest.

```cpp
void longestPalindrome(const string& s, int b, int e, int &start, int &last) {
    // 这个函数尝试对现有子串首尾扩张，若出现更大的长度，则记录之。
    int len = s.size();
    while (b >= 0 && e < len && s[b] == s[e])
        --b, ++e;
    ++b, --e;
    if (e - b > last - start) {
        start = b;
        last = e;
    }
}
```

主函数里就非常轻松惬意了。

```cpp
string longestPalindrome(string s) {
    int len = s.size();
    if (len == 0) return s;
    int start = 0, last = 0;
    for (int i=0; i<len-1; ++i) {
        longestPalindrome(s, i, i, start, last); // 奇数情况
        longestPalindrome(s, i, i+1, start, last); // 偶数情况
    }
    return s.substr(start, last-start+1);
}
```

时间复杂度应该在 O(n^2), 空间复杂度为 O(1). 属于常规解法。

-----

此题可以做到 O(n) 的时间复杂度。请参考[这里](http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html).
