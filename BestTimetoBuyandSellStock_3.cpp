/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        vector<int> dp(prices.size(), 0);
        int ret = 0;
        int minPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        int maxPrice = prices[prices.size() - 1];
        int temp = 0;
        ret = dp[prices.size() - 1];
        for(int j = prices.size() - 2; j >= 0; j--)
        {
            temp = max(temp, maxPrice - prices[j]);
            maxPrice = max(maxPrice, prices[j]);
            int sum = temp;
            if(j > 0)
                sum = sum + dp[j - 1];
            if(sum > ret)
                ret = sum;
        }
        return ret;
    }
};
