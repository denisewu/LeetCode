/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
class Solution {
     int largestRectangleArea(vector<int> &height) {
        stack<int> s;
    	int maxArea = 0;
    	if(height.empty())
    		return 0;
    	if (height.size() == 1)
    		return height[0];
    
        	int i = 0;
    	while( i < height.size())
    	{
    		if(s.empty() || height[i] >= height[s.top()])
    			s.push(i++);
    		else
    		{
    			int start = s.top();
    			s.pop();
    			int width = s.empty()? i: i - s.top() - 1;
    			maxArea = max(maxArea, height[start] * width);
    		}
    	}
    	while(!s.empty())
    	{
    		int start = s.top();
    		s.pop();
    		int width = s.empty()?height.size(): height.size() - s.top() - 1;
    		maxArea = max(maxArea, height[start] * width);
    	}
    	return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int total = 0;
        if(matrix.empty())
            return total;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += (matrix[i][j] - '0');
            }
            int area = largestRectangleArea(height);
            if(area > total)
                total = area;
        }
        return total;
    }
};
