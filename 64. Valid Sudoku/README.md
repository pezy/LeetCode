这个解法效率一般，在cpp里算是中档水平。但我觉得非常简单易懂。

数独的规则非常明了：

1. 行不能有重复
2. 列不能有重复
3. 九宫格不重复

于是我对应这三个规则设计了三个 hash 表：

    std::unordered_map<size_t, std::unordered_set> row_map, col_map, cel_map;
    //                ^                 ^          ^ 1      ^ 2      ^ 3
    //      index of row/col/cell   have shown number.

好的数据结构，可以大面积缩短算法描述，在这道题里展现的淋漓尽致。这三个 hash 表一出，我想接下来应该无需赘述了吧。

遍历整个 board，insert 到相应的 hash 表中，如果遇到插入失败的， `return false` 即可。

唯一值得一提的是，cell 其实是没有 index 的，这个只需要自己制定一个规则即可。我制定的是：

    size_t cell_index = i/3 * 10 + j/3;
    // 那么9个 cell 的 index 依次为：0, 1, 2, 10, 11, 12, 20, 21, 22.

-----

从这道题可以看出 *C++ Primer 5th* 的经典，因为同样的思路和代码，出现在昨晚我提交的课后习题里。。。
