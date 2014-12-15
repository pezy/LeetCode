#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    std::vector<std::vector<int>> vec{{0,0,0},{0,1,0},{0,0,0}};
    std::cout << s.uniquePathsWithObstacles(vec) << std::endl;
    
    std::vector<std::vector<int>> vec1{{1,1}};
    std::cout << s.uniquePathsWithObstacles(vec1) << std::endl;

    return 0;
}
