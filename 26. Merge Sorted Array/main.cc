#include "solution.h"
#include <iostream>

int main()
{
    int A[14] = {1,3,5,7,9,14};
    int B[] = {2,4,6,8,10,11,12,13};
    Solution s;
    s.merge(A, 6, B, 8);
    for (auto i : A)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
