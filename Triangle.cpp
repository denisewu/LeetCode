/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int ret;
        if(triangle.empty())
            return ret;
        vector<int> booking(triangle[triangle.size() - 1].size());
        for(int i = 0; i < triangle.size(); i++)
        {
            int row = (int)triangle.size() - i - 1;
            for(int j = 0; j < triangle[row].size(); j++)
            {
                if(i == 0)
                {//last row
                    booking[j] = triangle[row][j];
                }
                else
                {
                    booking[j] = min(booking[j], booking[j + 1]);
                    booking[j] += triangle[row][j];
                }
            }
            
        }
        return booking[0];
    }
};
