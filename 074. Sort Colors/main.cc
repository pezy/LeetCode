#include "solution.h"
#include <iostream>

int main()
{
    int A[] = {1,2,0,0,1,0,2,1};
    Solution s;
    s.sortColors(A, 8);
    for (auto i : A)
        std::cout << i << std::endl;
    return 0;
}
