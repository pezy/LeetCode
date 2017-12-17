#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (const auto &v : s.combine(4, 2))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    return 0;
} 
