昨天那道题的逆向。

重新回顾一下 Roman numberals 的概念：

Symbol|Value
------|------
I|1
V|5
X|10
L|50
C|100
D|500
M|1,000

- the numeral I can be placed before `V` and `X` to make **4 units (`IV`)** and **9 units (`IX`)** respectively
- `X` can be placed before `L` and `C` to make **40 (`XL`) and 90 (`XC`)** respectively
- `C` can be placed before `D` and `M` to make **400 (`CD`) and 900 (`CM`)** according to the same pattern[5]

把下面三条特殊说明也补充到上表中，成为：

Symbol|Value
------|------
I|1
IV|4
V|5
IX|9
X|10
XL|40
L|50
XC|90
C|100
CD|400
D|500
CM|900
M|1,000

突然发现，根据这个表，几乎全部阿拉伯数字都可以罗马数字表示了。那么解决这道题，显然就需要缓存这张表，基于这张表进行快速检索了。
于是我们很自然的使用了 std::map 。但在拿到一个阿拉伯数字的时候，如 2014，我们肯定要从高位去匹配，如先匹配1000，所以在迭代检索的时候，
还是要**逆向迭代**。

-----

加上昨天那道题，我十分想建议 C++ 标准委员会：能否加一个 range for 的逆向迭代？如 for (auto i : ~map) 之类。

-----

匹配上1000，我们将结果字符串 ret + “M”， 然后将该数字减去匹配值，2014-1000=1014, 这个时候其实还需要匹配1000，所以，
在逆向迭代map的时候，我们还应该添加一个循环确认该数字不会再匹配该key。
```cpp
while (num >= iter.first)
{
  ret += map[iter.first];
  num -= iter.first;
}
```

这道题总体来说，写的很顺。重点就是那个表的构建了。
