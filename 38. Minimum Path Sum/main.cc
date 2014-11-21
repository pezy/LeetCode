#include "solution.h"
#include <iostream>

int main()
{
    std::vector<std::vector<int> > vec{{0,2,1,5,2,6,9},{3,5,4,7,4,3,8},{6,9,3,8,5,7,0}};
    Solution s;
    std::cout << s.minPathSum(vec) << std::endl;
    return 0;
}
