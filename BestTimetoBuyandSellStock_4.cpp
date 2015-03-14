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
        
        vector<int> balance(k + 1, INT_MIN), profit(k + 1);

        for(int i = 0; i < len; ++i) {
            for(int j = 1; j <= k; ++j) {
                balance[j] = max(profit[j - 1] - prices[i], balance[j]); // whether buy at prices[i]
                profit[j] = max(balance[j] + prices[i], profit[j]); // whether sell at prices[i]
            }
        }

        return profit[k];
    }
};
