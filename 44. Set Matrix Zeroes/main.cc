#include "solution.h"
#include <iostream>

int main()
{
    std::vector<std::vector<int> > vec{{1,2,0,5},{0,2,3,4},{7,6,8,9},{3,5,7,1}};
    Solution s;
    s.setZeroes(vec);
    for (const auto &v : vec) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
