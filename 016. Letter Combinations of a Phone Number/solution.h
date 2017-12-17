//
//  Solution.h
//  Test
//
//  Created by pezy on 12/27/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef Test_Solution_h
#define Test_Solution_h

#include <vector>
#include <string>
#include <array>

using std::vector; using std::string; using std::array;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret{""};
        array<string, 10> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto digit : digits) {
            vector<string> tmp;
            for (auto c : map[digit - '0'])
                for (const auto &pre : ret)
                    tmp.push_back(pre + c);
            ret = tmp;
        }
        return ret;
    }
};

#endif
