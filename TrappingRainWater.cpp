/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 2)
            return 0;
        int rain = 0;
        int maxl = A[0];
        vector<int> leftMax(n, 0);
        for(int i = 1; i < n; i++)
        {
            leftMax[i] = maxl;
            if(A[i] > maxl) maxl = A[i];
        }
        int maxr = A[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            int bar = min(leftMax[i], maxr);
            if(bar > A[i]) rain += (bar - A[i]);
            if(A[i] > maxr) maxr = A[i];
        }
        
        return rain;
        
    }
};
