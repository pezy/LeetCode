首先，这个组合的顺序与 `std::next_permutation` 的顺序一致。可以参考 [排列组合技术](http://segmentfault.com/blog/pezy/1190000002486075)。


但如果这道题，直接使用 `std::next_permutation` 的话，会 TimeOut.

所以应该直接定位到 k 位置的字符串，而不是将所有组合都迭代一遍。

-----

需要两个索引表：

**table**

| n | 组合个数 |
|:-:|:--------:|
| 0 |     1    |
| 1 |    1!    |
| 2 |    2!    |
| 3 |    3!    |
| 4 |    4!    |
| 5 |    5!    |
| 6 |    6!    |
| 7 |    7!    |
| 8 |    8!    |
| 9 |    9!    |

**dictionary**

    1 2 3 4 5 6 7 8 9
    
那么如果有了 k, 对于长度为 n 的字符串来说，首先要定位的是其开头字符。

    int pos = (k-1)/table[n-1];
    ret += dict[pos];

出现过的字符，不应再有机会出现，故删除之。并继续查看后面的字符。同时 k 也要减掉之前计算过的 pos.

    dict.earse(dict.begin() + pos);
    k = k - pos * table[n-1];
