/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n)
            return 0;
            
        vector<vector<int> > book;
        for(size_t i = 0; i < m; i++)
        {
            vector<int> v(n);
            book.push_back(v);
        }
        for(size_t i = 0; i < m; i ++)
            book[i][n - 1] = 1;
        for(size_t j = 0; j < n; j++)
            book[m - 1][j] = 1;
            
        if(m > 1 && n >1)
        {
            for(int i = m - 2; i >= 0; i--)
            {
                for(int j = n - 2; j >= 0; j--)
                {
                    book[i][j] = book[i + 1][j] + book[i][j + 1];
                }
            }
        }
        
        return book[0][0];
    }
};
