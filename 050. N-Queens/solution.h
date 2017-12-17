#include <vector>
#include <string>

using std::vector; using std::string;

class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> queens(n, 0);
        solveNQueens(0, queens);
        return ret;
    }
    
    void solveNQueens(int row, vector<int> queens) {
        int size = queens.size();
        if (row == size) {
            vector<string> solution(size, string(size, '.'));
            for (int r=0; r<size; ++r)
                solution[r][queens[r]] = 'Q';
            ret.push_back(solution);
        } else for (int col=0; col<size; ++col) {
            queens[row] = col;
            if (isValid(row, col, queens)) solveNQueens(row+1, queens);
        }
    }
    
    bool isValid(int row, int col, const vector<int> &queens) {
        for (int queen_col=0, r=row-1, lc=col-1, rc=col+1; r>=0; --r, --lc, ++rc) {
            queen_col = queens[r];
            if (queen_col == col || queen_col == lc || queen_col == rc) return false;
        }
        return true;
    }
};
