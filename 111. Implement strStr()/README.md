这道题不要去考虑什么 [Rabin-Karp](http://en.wikipedia.org/wiki/Rabin-Karp_algorithm), [KMP](http://en.wikipedia.org/wiki/Knuth-morris-pratt_algorithm) 或是 [Boyer-Moore](http://en.wikipedia.org/wiki/Boyer_moore_algorithm) 算法，这就是一道 Easy 难度的基础题。

考察的是对于字符串指针的使用。

-----

我们在链表题中千锤百炼，以为练就了一身[弹指神通](http://segmentfault.com/blog/pezy/1190000002490878)的硬功夫。可是遇到这一题，东邪门人恐怕要吃亏。亏就亏在字符串指针的特殊性。

哪里特殊呢？

在链表中，我们通常会判断一个指针是否为 `nullptr`, 如 `if (p) //...`.

但在字符串指针中，这样的判断通常没有任何意义。对于字符串，举例说明：

        "hello,world"

在内存中的布局实际是这样：

	|h|e|l|l|o|,|w|o|r|l|d|\0|
                                ^
                                p

如何判断一个指向字符串的指针已经走到了尽头？如上图 `p` 指向的是 `\0`, 那么显然此时 `p != nullptr`, 因为它明显指向了一个字符。但这个字符非常特殊，我们称其为 **null character**, 如果我们对该指针取值，得到 `*p`, 可以得到 `*p == 0`。

这是一个非常重要的结论。所以我们在字符串指针中，通常使用的判断是诸如 `if (!*p) //...` 这样的。

-----

回到这道题，是非常基本的思路。迭代指针 `p`, 从 0 迭代到 n-m+1. (为什么是 n-m+1 ? n 是 `haystack` 的长度，m 是 `needle` 的长度，但 p 指向的后续字符个数小于了 `needle` 的字符个数，无论如何都无法匹配上了，所以继续迭代毫无意义。)

迭代过程中，我们设置两个临时指针 `p1`, `p2`, 分别遍历 `haystack` 与 `needle`. 逐一比较，若出现不符则继续进行下一次迭代。一直吻合，但 `p1` 或是 `p2` 有任意一个走到尽头，那么加以判断：

```cpp
if (!*p2) return p-haystack; // needle 全部匹配上了，返回位置。
else if (!*p1) break; // 已经到达 n-m+1 范围
```

剩下不表。