#include <cmath> 

class Solution {
public:
    double pow(double x, int n) {
        if (!n) return 1;
        double tmp = pow(x, n/2);
        return n&0x1 ? n>0 ? x * tmp * tmp : tmp * tmp / x : tmp * tmp;
    }
};
