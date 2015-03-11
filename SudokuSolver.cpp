/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
    bool cols[9][9] ;
    bool rows[9][9];
    bool boxes[9][9] ;
    
    bool solveSudokuAux(vector<vector<char> > &board, int pos)
    {   
        if(pos == 81)
            return true;
        int r = pos / 9;
        int c = pos % 9;
        if(board[r][c] != '.')
            return solveSudokuAux(board, pos + 1);
        else
        {
            for(int i = 1; i < 10; i++)
            {
                int boxindex = (r / 3) * 3 + (c / 3);
                if(!cols[i - 1][c] && !rows[i - 1][r] && !boxes[i - 1][boxindex])
                {
                    board[r][c] = i + '0';
                    cols[i - 1][c] = rows[i - 1][r] = boxes[i - 1][boxindex] = true;
                    if(solveSudokuAux(board, pos + 1))
                        return true;
                    board[r][c] = '.';
                    cols[i - 1][c] = rows[i - 1][r] = boxes[i - 1][boxindex] = false;
                }
            }
            return false;
        }
    }
    
public:
    void solveSudoku(vector<vector<char> > &board) {
        memset(cols, 0, 81 * sizeof(bool));
        memset(rows, 0, 81 * sizeof(bool));
        memset(boxes, 0, 81 * sizeof(bool));
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.' )
                {
                    int val = board[i][j] - '0';
                    cols[val - 1][j] = true;
                    rows[val - 1][i] = true;
                    int boxindex = (i / 3) * 3 + (j / 3);
                    boxes[val - 1][boxindex] = true;
                }
            }
        solveSudokuAux(board, 0);
    }
};
