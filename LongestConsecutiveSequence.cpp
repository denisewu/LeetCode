/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
       map<int, int> mp;
       for(int i = 0; i < num.size(); i++)
            mp[num[i]] = 1;
        
        int ret = 0;
        for(int i = 0; i < num.size(); i++)
        {
            int sum = 0;
            if(mp[num[i]] > 0)
            {
                int n = num[i];
                while(mp.count(n))
                {
                    mp[n] = 0;
                    n--;
                }
                sum +=  num[i] - n;
                n = num[i];
                while(mp.count(n))
                {
                    mp[n] = 0;
                    n++;
                }
                sum += n - num[i] - 1;
                if(sum > ret)
                    ret = sum;
            }
        }
        return ret;
    }
};
