#include "solution.h"
#include <iostream>

int main()
{
    Solution s;
    for (const auto &v : s.partition("aaba")) {
        for (const auto &s : v) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
}
