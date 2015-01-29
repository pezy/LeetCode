#include <climits>

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        do {
            res = res*10 + x%10;
        } while (x /= 10);
        return res>INT_MAX ? 0 : res;
    }
};
        
