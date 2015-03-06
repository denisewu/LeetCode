
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
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
};
