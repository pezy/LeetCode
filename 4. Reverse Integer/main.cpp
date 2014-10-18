#include <iostream>
#include "solution.h"

int main()
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(10100) << std::endl;
    std::cout << s.reverse(1000000003) << std::endl;

    return 0;
}
