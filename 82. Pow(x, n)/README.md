这道题题干之简洁，令人乍舌。太简洁，以至于完全不知道从哪里着手。

半开玩笑的试试：

```cpp
double pow(double x, int n) {
    return std::pow(x, n);
}
```

竟然也能以最高效的方式 AC，真是让人捧腹大笑。

-----

点一下 `show Tags`, 才发现机缘: Math, **Binary Search**.

起码给了我们一个方向，二分搜索的本质，是分治法。分而治之，各个击破，回到这道题:

    x^n = x^(n/2) * x^(n/2) --- n 为偶数
    x^n = x * x^(n/2) * x^(n/2) --- n 为奇数

这就是我能想到最简洁的分治递归式，再简化一下问题，我们假设 n 为正整数，x 为 `int`, 返回值为 `int`.

```cpp
int pow(int x, unsigned n) {
    if (!n) return 1;
    else if (n&0x1) return x * pow(x, n/2) * pow(x, n/2);
    else return pow(x, n/2) * pow(x, n/2);
}
```

这样的时间复杂度: O(n), 空间复杂度: O(1).

如果考虑将 pow(x, n/2) 记录下来，时间复杂度可以优化至 O(logn) :

```cpp
int pow(int x, unsigned n) {
    if (!n) return 1;
    int tmp = pow(x, n/2);
    else if (n&0x1) return x * tmp * tmp;
    else return tmp * tmp;
}
```

回到这道题，如果 x 为 `double`, n 为 `int`, 返回值为 `double` :

```cpp
double pow(double x, int n) {
    if (!n) return 1;
    double tmp = pow(x, n/2);
    return n&0x1 ? n>0 ? x * tmp * tmp : tmp * tmp / x : tmp * tmp;
}
```
