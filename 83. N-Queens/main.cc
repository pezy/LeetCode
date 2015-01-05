#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (const auto &v : s.solveNQueens(8)) {
        for (const auto &s : v)
            std::cout << s << std::endl;
        std::cout << std::endl;
    }
}
