#include "solution.h"
#include <iostream>
#include <bitset>

int main()
{
    Solution s;
    for (auto i : s.grayCode(4))
        std::cout << (std::bitset<4>)i << " ";
    std::cout << std::endl;
    return 0;
}
