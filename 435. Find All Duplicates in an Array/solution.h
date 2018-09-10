#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for (size_t i = 0; i != nums.size(); ++i) {
            size_t id = static_cast<size_t>(std::abs(nums[i]) - 1);
            if (nums[id] < 0) ret.push_back(id + 1);
            nums[id] = -nums[id];
        }
        return ret;
    }
};