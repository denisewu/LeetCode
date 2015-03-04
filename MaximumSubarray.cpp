/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/


class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return A[0];
            
        vector<int> dp(n + 1);
        int sum = A[0];
        dp[0] = 0;
        dp[1] = A[0];
        for(int i = 2; i < n + 1; i++)
        {
            dp[i] = max(dp[i - 1] + A[i - 1], A[i - 1]);
            if(dp[i] > sum)
                sum = dp[i];
        }
        return sum; 
    }
};
