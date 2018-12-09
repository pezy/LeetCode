#include <algorithm>
#include <vector>
using std::vector;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    for (int i = 1; i < k; ++i) {
      nums[i] += nums[i - 1];
    }
    double sum = nums[k - 1];
    for (int i = k; i < nums.size(); ++i) {
      nums[i] += nums[i - 1];
      sum = std::max<double>(sum, nums[i] - nums[i - k]);
    }
    return sum / k;
  }
};
