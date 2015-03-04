/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
    void spiralOrderInShell(vector<vector<int> > & matrix, 
        int left, int right, int top, int down, vector<int>& ret)
    {
        for(int i = left; i <= right; i++)
            ret.push_back(matrix[top][i]);
        
        for(int i = top + 1; i <= down; i++)
            ret.push_back(matrix[i][right]);
            
        if(down > top)
        {
            for(int i = right - 1; i >= left; i--)
                ret.push_back(matrix[down][i]);
        }
        
        if(right > left)
        {
            for(int i = down - 1; i > top; i--)
                ret.push_back(matrix[i][left]);
        }
    }
    
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
            
        int left = 0, top = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
        while(left <= right && top <= down)
        {
            spiralOrderInShell(matrix, left, right, top, down, ret);
            left++;
            right--;
            top++;
            down--;
        }
        return ret;
    }
};
