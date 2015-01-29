#include <vector>
#include <functional>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        std::vector<int> vec = {0,1,2,3};
        if (n > 3) vec.resize(n+1, -1);
        std::function<int(int)> fib = [&](int n)
        {
            if (vec[n] == -1)
                vec[n] = fib(n-1) + fib(n-2);
            return vec[n];
        };
        return fib(n);
    }
};
