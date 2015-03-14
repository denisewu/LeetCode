/*
iven a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
    int rows, cols;
    void pushq(vector<vector<char> > &board, queue<pair<int, int> > &q, int i , int j)
    {
        if(board[i][j] == 'O')  
        {
            board[i][j] = '#';
            q.push(pair<int, int>(i, j));
        }
    }
    
    void bfs(vector<vector<char> > &board, int i, int j)
    {
        if(board[i][j] != 'O')
            return;
            
        board[i][j] = '#';
        queue<pair<int, int> > q;
        q.push(pair<int, int>(i, j));
        while(!q.empty())
        {
            pair<int, int> pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            if(x > 0)
                pushq(board, q, x - 1, y);
            if(x < rows - 1)
                pushq(board, q, x + 1, y);
            if(y > 0)
                pushq(board, q, x, y - 1);
            if(y < cols - 1)
                pushq(board, q, x, y + 1);
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        rows = board.size();
        if(rows < 1)
            return;
        cols = board[0].size();
        if(rows < 3 || cols < 3)
            return;
        
        for(int i = 0; i < rows; i++)
        {
            bfs(board, i, 0);
            bfs(board, i, cols - 1);
        }
        for(int i = 0; i < cols; i++)
        {
            bfs(board, 0, i);
            bfs(board, rows - 1, i);
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
