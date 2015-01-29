#include "solution.h"
#include <iostream>
 
int main()
{
    Solution s;
    vector<int> vec{9,9,9,9};
    vec = s.plusOne(vec);
    for (auto i : vec) std::cout << i;
    std::cout << std::endl;
    return 0;
}
