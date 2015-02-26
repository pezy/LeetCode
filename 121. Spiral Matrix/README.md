m * n 的矩阵按螺旋顺序转为数组：

    1 2 3
    4 5 6     -->     1 2 3 6 9 8 7 4 5
    7 8 9

我想到的是，直接用下标作为限制。m 行，n 列，即范围:

- row: 0 ~ m
- col: 0 ~ n

首先是列递增，(0,0), (0,1), (0,2). 然后行递增，(1,2), (2,2). 再后是列递减，(2,1), (2,0). 和行递减，(1,0).
最后进入下一螺旋：(1,1). 到此为止，全部数组都迭代出来。

可以发现的规律是，每一次螺旋，都按照以下顺序：

1. 列递增 (row 降到最低)
2. 行递增 (col 增到最高)
3. 列递减 (row 增到最高)
4. 行递减 (col 降到最低)

写成 `for` 循环的形式，则为：

```cpp
for (; nMin<mMax && nMin<nMax; --mMax, --nMax, ++mMin, ++nMin) {
    for (int i=nMin; i<nMax; ++i)
        ret.push_back(matrix[mMin][i]);
    for (int i=mMin+1; i<mMax; ++i)
        ret.push_back(matrix[i][nMax-1]);
    for (int i=nMax-2; i>=nMin; --i)
        ret.push_back(matrix[mMax-1][i]);
    for (int i=mMax-2; i>mMin; --i)
        ret.push_back(matrix[i][nMin]);
}
```

除此之外，需要增加一些边界条件判断：

- `n = matrix[0].size();` // 要提前判断 matrix.empty()
- 第三个 `for` 循环要避免重复，如仅有一行的情况，列递增之后，没有行递增，直接就列递减了，那必然重复。判断 `mMax-1 != mMin`.
- 第四个 `for` 循环同理，避免行重复，判断 `nMax-1 != nMin`.
