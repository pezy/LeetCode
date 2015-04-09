#include <iostream>
#include "solution.h"
//#include "divide_conquer.h"

int main()
{
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    std::cout << s.maxSubArray(A, 9) << std::endl;

    return 0;
}
