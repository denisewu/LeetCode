/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
    int quickSolve(vector<int> &prices)
    {
        int sum = 0;
        for(int i = 1; i < (int)prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
                sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
    
public:
    int maxProfit(int k, vector<int> &prices) {
       int len = prices.size();
       if(k >= len / 2)
            return quickSolve(prices);
        
        vector<vector<int> > dp(k + 1, vector<int>(len, 0));
        for(int i = 1; i < k + 1; i++){
            int tempmax = 0 - prices[0];
            for(int j = 1; j < len; j++)
            {
                dp[i][j] = max(dp[i][j - 1], tempmax + prices[j]);
                tempmax = max(tempmax, dp[i - 1][j - 1] - prices[j]);
            }
            
        }
        return dp[k][len - 1];
    }
};
