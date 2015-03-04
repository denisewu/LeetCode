//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        if(n == 0)
            return ret;
        for(int i = 0; i < n; i++)
        {
            vector<int> v(n, 0);
            ret.push_back(v);
        }
        
        int left = 0 , right = n - 1, top = 0, down = n - 1;
        int j = 1;
        while(left <= right && top <= down)
        {
            for(int i = left; i <= right; i++)
                ret[top][i] = j++;
            
            for(int i = top + 1; i <= down; i++)
                ret[i][right] = j++;
                
            if(top < down)
            {
                for(int i = right - 1; i >= left; i--)
                    ret[down][i] = j++;
            }
            
            if(left < right)
            {
                for(int i = down - 1; i > top; i--)
                    ret[i][left] = j++;
            }
            left++;
            right--;
            top++;
            down--;
        }
        return ret;
    }
};
