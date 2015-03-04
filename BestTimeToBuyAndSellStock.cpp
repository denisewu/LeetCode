/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        if(prices.empty())
            return ret;
        int minPrice = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] > minPrice)
                ret = max(ret, prices[i] - minPrice);
            else
                minPrice = prices[i];
        }
        return ret;
    }
};
