/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        if(n < 1)
            return dp[0];
        if(n < 2)
            return 1;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++)
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
    
        return dp[n];
    }
    
};
