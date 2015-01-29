#include <iostream>
#include "solution.h"

int main()
{
    //vector<int> prices;
    vector<int> prices = {4, 3, 4, 5, 7, 8, 9, 10, 4, 6, 3};
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
}
