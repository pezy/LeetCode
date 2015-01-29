#include "solution.h"
#include <iostream>

using namespace std;

int main()
{
    Solution s;
    std::vector<int> vec{10,1,2,7,6,1,5};
    for (const auto &v : s.combinationSum2(vec, 8)) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

