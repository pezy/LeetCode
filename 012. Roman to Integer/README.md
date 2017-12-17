重点读了一下什么是[Roman numberals](http://en.wikipedia.org/wiki/Roman_numerals). 看完之后，明确以下几点规则：

1. 基本字符表：I V X L C D M (1, 5, 10, 50, 100, 500, 1000)
2. the numeral `I` can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively.
3. `X` can be placed before L and C to make 40 (XL) and 90 (XC) respectively.
4. `C` can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern.

由于要累计总数，肯定是**逆循环**解析字符串，遇到`I`,`X`,`C`要特殊处理，即判断在左还是在右，左要减，右要加。
其余字符，加上其所代表的阿拉伯数字即可。

代码非常简单，不赘述。
