int largestRectangleArea(vector<int> &height) 
{ 
	stack<int> s;
	int maxArea = 0;
	if(height.empty())
		return 0;
	if (height.size() == 1)
		return height[0];

	while( i < height.size())
	{
		if(s.empty() || height[i] >= height[s.top()])
			s.push_back(i++);
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
