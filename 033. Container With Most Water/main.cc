#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    vector<int> vec{1,2,4,3};    
    std::cout << s.maxArea(vec) << std::endl;

    return 0;
}
