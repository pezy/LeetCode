#include <vector>

using std::vector; 

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec;
        for (int i=0; i<numRows; ++i) {
            vector<int> row;
            if (!vec.empty()) row.assign(vec.at(i-1).begin(), vec.at(i-1).end());
            row.push_back(1);
            for (int j=i-1; j>0; --j)
                row[j] += row[j-1];
            vec.push_back(row);
        }
        return vec;
    }
};
