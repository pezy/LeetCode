#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> steps;
        for (auto &v : triangle) {
            if (!steps.empty()) {
                v.front() += steps.front();
                v.back() += steps.back();
            }
            for (size_t i=1; i<steps.size(); ++i)
                v[i] += min(steps.at(i-1), steps.at(i));
            steps = v;
        }
        return *min_element(steps.cbegin(), steps.cend());
    }
};
