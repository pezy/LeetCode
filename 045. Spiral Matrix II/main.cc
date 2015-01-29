#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (const auto &v : s.generateMatrix(5)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
