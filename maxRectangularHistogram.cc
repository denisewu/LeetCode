class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        vector<int> right(height.size());
        for(int i=0;i<height.size();i++)
        {
            while(!s.empty())
            {
                if(height[s.top()]>height[i])
                {                    
                    right[s.top()]=i;
                    s.pop();
                }
                else
                    break;
            }
            s.push(i);
                        
        }
        while(!s.empty())
        {
            right[s.top()]=height.size();
            s.pop();
        }
        vector<int> left(height.size());
        for(int i=height.size()-1;i>-1;i--)
        {
            while(!s.empty())
            {
                if(height[s.top()]>height[i])
                {
                    left[s.top()]=i;
                    s.pop();
                }
                else
                    break;
            }
            s.push(i);
        }
        while(!s.empty())
        {
            left[s.top()]=-1;
            s.pop();
        }
        int maxSize=0;
        for (int i=0;i<height.size();i++)
        {
            int size=height[i]*(right[i]-left[i]-1);
            if (i==0)
                maxSize=size;
            else if (size>maxSize)
                maxSize=size;
        }
        return maxSize;
    }
};