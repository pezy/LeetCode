#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> vec{1,2,3};
    for (const auto &v : s.subsets(vec)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}
