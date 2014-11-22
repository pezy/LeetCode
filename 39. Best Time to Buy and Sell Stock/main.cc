#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> vec{2,4,3,7,9,2,5,6,10,1};
    std::cout << s.maxProfit(vec) << std::endl;
    return 0;
}
