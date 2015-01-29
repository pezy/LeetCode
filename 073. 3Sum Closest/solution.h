#include <vector>
#include <algorithm>
using std::vector; 

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int min{INT_MAX}, sum{0}, tmpsum{0};
        for (auto it=num.cbegin(); it!=num.cend(); ++it)
            for (auto b = std::next(it), e = std::prev(num.cend()); b<e; tmpsum > target ? --e : ++b)
                if ((tmpsum = *it + *b + *e) == target) return target;
                else if (std::abs(tmpsum - target) < min) {sum = tmpsum; min = std::abs(tmpsum - target);}
        return sum;
    }
};
