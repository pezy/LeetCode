#include "solution.h"
#include <iostream>

using namespace std;

int main()
{
    Solution s;
    vector<string> vec = {"cat","rye","aye","dog", "god","cud","cat","old","fop","bra"};
    for (const auto &str : s.anagrams(vec))
        cout << str << " ";
    cout << endl;

    return 0;
}

