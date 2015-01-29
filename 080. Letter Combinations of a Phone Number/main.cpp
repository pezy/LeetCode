#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (const auto &str : s.letterCombinations("23")) {
        std::cout << str << std::endl;
    }
}
