/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
    void solveQueensAux(int n, int row, vector<int>& colForRow, vector<vector<string> >& ret)
    {
        if(row == n)
        {
            vector<string> queens;
            for(int i = 0; i < n; i++)
            {
                int col = colForRow[i];
                string rowstr = "";
                for(int j = 0; j < col; j++)
                    rowstr += ".";
                rowstr += "Q";
                for(int j = col + 1; j < n; j++)
                    rowstr += ".";
                queens.push_back(rowstr);
            }
            ret.push_back(queens);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            colForRow[row] = i;
            if(check(row, colForRow))
            {
                solveQueensAux(n, row + 1, colForRow, ret);
            }
        }
    }
    bool check(int row, vector<int>& colForRow)
    {
        for(int i = 0; i < row; i++)
        {
            if(colForRow[i] == colForRow[row] || 
               abs(colForRow[i] - colForRow[row]) == row - i )
                return false;
        }
        return true;
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> colForRow(n, -1);
        vector<vector<string> > ret;
        solveQueensAux(n, 0, colForRow, ret);
        return ret;
    }
};
