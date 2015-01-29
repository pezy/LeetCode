#include <iostream>
#include "Solution.h"

int main()
{
    int A[] = {1,3,5,6};
    Solution s;
    std::cout << s.searchInsert(A, 4, 5) << std::endl;
    std::cout << s.searchInsert(A, 4, 2) << std::endl;
    std::cout << s.searchInsert(A, 4, 7) << std::endl;
    std::cout << s.searchInsert(A, 4, 0) << std::endl;
    return 0;
}
