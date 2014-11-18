#include "solution.h"
#include <iostream>

void print(const vector<vector<int> > &matrix)
{
    for (auto v : matrix)
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

int main()
{
    Solution s;
    std::vector<std::vector<int> > vec{{1,2,3},{4,5,6},{7,8,9}};
    print(vec);
    
    s.rotate(vec);
    std::cout << "===========" << std::endl;
    print(vec);
    
    return 0;
}
