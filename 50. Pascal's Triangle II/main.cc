#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (auto i : s.getRow(4))
        std::cout << i << " ";
    
    return 0;
}
