这题的主要思路参考 [75. Combination Sum](../75. Combination Sum), 大同小异，涉及的思想，依旧是 DFS。

要额外注意的有两点：

1. Each number in **C** may only be used **once** in the combination.
2. The solution set must not contain duplicate combinations.

对于第一点，我们可以在递归中，给下一个 `start` 传参为 `i+1` 来解决。

对于第二点，有两种思路：

1. 使用 `std::set<vector<int>>` 来存储返回值，缺点是效率较低。
2. 在递归函数中增加条件：`if (i > start && num[i] == num[i-1]) continue;` 无比轻巧的避过了重复项。

我当然选择了第二种，效率遥遥领先呢。
