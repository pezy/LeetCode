#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (auto vec : s.generate(5))
    {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
