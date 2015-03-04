/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool col[9][9] = {false}, row[9][9] = {false}, box[9][9] = {false};
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    int num = c - '0' - 1;
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if(col[num][i] || row[num][j] || box[num][boxIndex])
                        return false;
                    col[num][i] = row[num][j] = box[num][boxIndex] = true;
                }
            }
        return true;
    }
};
