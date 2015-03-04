/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum = 0;
        vector<int> candies(ratings.size());
        for(int i = 0 ; i < ratings.size(); i++)
        {
            if(i == 0)
                candies[i] = 1;
            else if(ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
            else
                candies[i] = 1;
        }
        
        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            {
                candies[i] = candies[i + 1] + 1;
            }
            sum += candies[i + 1];
        }
        
        sum += candies[0];
        return sum;
    }
};

