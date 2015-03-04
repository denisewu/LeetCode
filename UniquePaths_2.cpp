/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() )
            return 0;
        vector<int> book(obstacleGrid[0].size(), 0);
        for(int i = obstacleGrid.size() - 1; i >= 0; i--)
            for(int j = obstacleGrid[i].size() - 1; j >= 0; j--)
            {
                if(obstacleGrid[i][j] == 1)
                    book[j] = 0;
                else if(i == obstacleGrid.size() - 1)
                {
                    if(j == obstacleGrid[i].size() - 1)
                        book[j] = 1;
                    else
                        book[j] = book[j + 1];
                }
                else if(j < obstacleGrid[i].size() - 1)
                {
                    book[j] = book[j] + book[j + 1];
                }
            }
        return book[0];
    }
};
