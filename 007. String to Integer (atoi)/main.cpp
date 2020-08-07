#include <iostream>
#include "solution.h"


int main() {
    string str;
    cin>>str;
    
    Solution s;
    std::cout << s.myAtoi(str) << std::endl;
    
	return 0;
}
