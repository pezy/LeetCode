#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> vec{1,2,2};
    for (const auto &v : s.subsetsWithDup(vec)) {
        std::cout << "[";
        for (auto i : v)
            std::cout << i << ",";
        std::cout << (v.empty() ? "]" : "\b]") << std::endl;
    }
}
