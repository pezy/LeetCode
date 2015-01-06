#include <vector>
using std::vector; 

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int tank{0}, start{0}, stored{0};
        for (decltype(gas.size()) i=0; i<gas.size(); ++i)
            if ((tank += gas[i] - cost[i]) < 0) {
                start = i + 1;
                stored += tank; 
                tank = 0;
            }
        return (tank + stored) < 0 ? -1 :start;
    }
};
