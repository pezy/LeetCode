这道题我拿到手就想到了 **回溯+DFS** 的思路。

因为这就是咱们人工去解数独的方法，看到空的格子，首先在脑海里列出能够放的数字列表，然后先试第一个，接着看后续的格子，采取同样的方式。如果发现不对劲了，回溯回去，用列表中的第二个，再试。如此反复，就可以得到完整的数独方案了。

数独的问题不是第一次见，可以回顾一下：[064. Valid Sudoku](https://github.com/pezy/LeetCode/tree/master/064.%20Valid%20Sudoku).

-----

我们来看题目中的例子：

    5 3 X | . 7 . . . .     | // X 的备选方案：
    6 . . |------------     | // row : 1 2 4 6 8 9
    . 9 8 | 1 9 5 . . .     | // col : 1 2 3 4 5 6 7 9
    ------| . . . . 6 .     | // cel : 1 2 4 7
    8 . . | . 6 . . . 3     |
    4 . . | 8 . 3 . . 1     |         S(0)
    7 . . | . 2 . . . 6     |         / | \
    . 6 . | . . . 2 8 .     |        1  2  4
    . . . | 4 1 9 . . 5     |        |  |  |
    . . . | . 8 . . 7 9     |  S(0,1) S(0,2) S(0,4)

从上图的分析来看，我们填写 X 的过程如下：

1. 确定(row, col)
2. 1 ~ 9 中逐一尝试放入 pos(row, col),  若没有，回到 1.
1. 若 cur_row, cur_col, cur_cell 出现重复，将 (row, col) 置为 '.', 回到 1.
2. 若无重复，填入该数字，回到 1.
3. 所有(row, col)都填满，成功。

针对第一步，我们需要一个函数，尝试遍历整个矩阵，找到第一个 '.' 的位置，立刻返回：

```cpp
bool findEmptyCell(const vector<vector<char> > &board, size_t &row, size_t &col)
{
    for (row = 0; row < board.size(); ++row)
        for (col = 0; col < board[row].size(); ++col)
            if (board[row][col] == '.') return true;
    return false;
}
```

针对第二步，检查重复，我们也需要一个函数，分别检查**同行**,**同列**,**同Cell**是否有重复。
```cpp
bool isSafe(const vector<vector<char> > &board, size_t row, size_t col, char c)
{
    for (size_t i=0; i<9; ++i) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[row/3 * 3 + i / 3][col/3 * 3 + i % 3] == c) return false;
    }
    return true;
}
```

第三步，实际可以复用第一步的结果，如果找不到 '.', 那么自然可以认为，已经全都填满。

最后我们只需要组织逻辑十分清晰的主体递归函数即可：

```cpp
bool solveSudoku(vector<vector<char> > &board) {
    size_t row = 0, col = 0;
    if (!findEmptyCell(board, row, col)) return true; // 第一步
    for (char c : {'1', '2', '3', '4', '5', '6', '7', '8', '9'}) // 第二步
    if (isSafe(board, row, col, c)) {
        board[row][col] = c;
        if (solveSudoku(board)) return true;
        board[row][col] = '.'; // 回溯
    }
    return false;
}
```

总共30行的代码。比起论坛里动辄百行的代码来说，是不是面试的时候遇到，更加有信心写出呢？

清晰简单的代码思路，通常也意味着效率并不高，这个答案提交，可能只是 C++ 中的垫底。

如果尝试用 hash 表来优化，可能就无法这么简洁了。（隐隐盼望可以）

------

随着 LeetCode 题目的难度升级，我有时可能无法做到一天一道题了。

风格，也从追求极致的效率，转变为短小精悍，意图清晰了。

毕竟，再高效的代码，你笔试面试的时候完全想不起来（或是不好理顺），也是白搭。
