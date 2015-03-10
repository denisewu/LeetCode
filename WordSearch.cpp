/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
    bool dfs(vector<vector<char> > &board, string word, int pos, int r, int c)
    {
        int m = board.size();
        int n = board[0].size();
        if(pos == word.size())
            return true;
        if(r <0 || r >= m|| c < 0 || c >= n 
            || board[r][c] == '#' || board[r][c] != word[pos])
            return false;
        //use it
        board[r][c] = '#';
        bool ret = dfs(board, word, pos + 1, r + 1, c) ||
                    dfs(board, word, pos + 1, r, c + 1) ||
                    dfs(board, word, pos + 1, r - 1, c) ||
                    dfs(board, word, pos + 1, r, c - 1);
        board[r][c] = word[pos];
        return ret;
    }
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            {
                if(dfs(board, word, 0,  i, j))
                    return true;
            }
        return false;
    }
};
