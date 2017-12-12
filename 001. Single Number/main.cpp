#include <iostream>
#include "solution.h"

// Unit Test

int main() 
{
    Solution s;
    int A[7] = {1,2,3,5,2,1,3};
    std::cout << s.singleNumber(A, 7) << std::endl;
}
