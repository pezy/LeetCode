这道题就是考察大数乘法了。

我们还是从简单的例子来分析：

    1234567 *
    8901234

想想，乘法是如何运算的，用比较小的数举例，更好理解：

        23 *
        43
        ----
        69 +
       92
       -----
       989

我们将 43 视作 num1, 23 视作 num2, 那么这是一个很明显的两级 `for` 循环。从尾部开始，外部遍历 num1, 内部遍历 num2. 注意进位。

如果给定的是字符串，显然，我们是从字符串的末尾开始遍历的。

另外一个隐藏的规律是：num1 * num2 结果的位数必然小于 num1 的位数 + num2 的位数。
所以可以设结果为 `string ret(num1.size() + num2.size(), '0');`

```cpp
for (size_t i = num1.size()-1; i >= 0; --i) {
    int carry = 0;
    for (size_t j = num2.size()-1; j >= 0; --j) {
        int sum = (ret[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
        ret[i+j+1] = sum % 10 + '0';
        carry = sum / 10;
    }
    ret[i] += carry;
}
```

得到的结果依旧是从尾部开始铺陈开的，所以最终还要去掉开头初始化时的 `0`。

```cpp
size_t pos = ret.find_first_not_of('0');
if (pos != string::npos) return ret.substr(pos);
else return "0";
```

提交 AC.
