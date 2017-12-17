#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (auto str : s.generateParenthesis(3))
        std::cout << str << std::endl;
    return 0;
} 
