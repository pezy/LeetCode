#include "solution.h"
#include <iostream>

using namespace std;

int main() {
    Solution s;
    //vector<int> vec{1,-2,-5,-4,-3,3,3,5};
    //vector<int> vec{-3,-2,-1,0,0,1,2,3};
    //vector<int> vec{1,0,-1,0,-2,2};
    vector<int> vec{-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    for (const auto &v : s.fourSum(vec, 0)) {
        for (auto i : v)
            cout << i << ",";
        cout << "\b " << endl;
    }
}
