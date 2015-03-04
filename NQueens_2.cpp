/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
      void solveQueensAux(int n, int row, vector<int>& colForRow, int& total)
    {
        if(row == n)
        {
            total++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            colForRow[row] = i;
            if(check(row, colForRow))
            {
                solveQueensAux(n, row + 1, colForRow, total);
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
    int totalNQueens(int n) {
        vector<int> colForRow(n, -1);
        int total = 0;
        solveQueensAux(n, 0, colForRow, total);
        return total;
    }
};
