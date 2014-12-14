#include <vector>
#include <unordered_map>
using std::vector; using std::unordered_map;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int max{0};
        for (auto i : num)
            if (!map[i]) {
                map[i] = map[i+1] + map[i-1] + 1;
                map[i-map[i-1]] = map[i+map[i+1]] = map[i];
                max = std::max(max, map[i]);
            }
        return max;
    }
};
