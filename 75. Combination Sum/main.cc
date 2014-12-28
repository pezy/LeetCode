#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> vec{2,3,6,7};
    for (const auto &v : s.combinationSum(vec, 7)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}
