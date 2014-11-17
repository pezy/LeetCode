#include "solution.h"
#include <iostream>

using std::cout; using std::endl; using std::vector;

int main()
{
    Solution s;
    vector<int> vec{0,-1,1};
    for (auto v : s.permute(vec))
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
} 
