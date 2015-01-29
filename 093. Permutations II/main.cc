#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> vec{1,1,2};
    for (const auto &v : s.permuteUnique(vec)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}
