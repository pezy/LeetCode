#include "solution.h"
#include <iostream>
using namespace std;

int main()
{
    Solution s;
    vector<string> ips = s.restoreIpAddresses("25525511135");
    for (const auto &ip : ips)
        cout << ip << endl;
}
