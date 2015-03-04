/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
class Solution {
    int max(int i, int j)
    {
        return i > j? i: j;     
    }
    
    int min(int i, int j)
    {
        return i < j? i: j;
    }
    
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2)
            return 0;
        
        int minnum = num[0], maxnum = num[0];
        for(int i = 1; i < num.size(); i++)
        {
            if(num[i] > maxnum)
                maxnum = num[i];
            if(num[i] < minnum)
                minnum = num[i];
        }
        
        int gap = max(1, (maxnum - minnum) / (num.size() - 1));
        int bucketnum = (maxnum - minnum) / gap + 1;
        vector<int> bucketMin(bucketnum, INT_MAX);
        vector<int> bucketMax(bucketnum, INT_MIN);
        vector<int> bucketCount(bucketnum, 0);
        for(int i = 0; i < num.size(); i++)
        {
            int index = (num[i] - minnum) / gap;
            bucketCount[index]++;
            bucketMin[index] = min(bucketMin[index], num[i]);
            bucketMax[index] = max(bucketMax[index], num[i]);
        }
        int maxGap = 0;
        gap = 0;
        int i = 0;
        int prevBucket = -1;
        while(i < bucketCount.size())
        {
            while(i < bucketCount.size() && bucketCount[i] == 0)
                i++;
            if(i < bucketCount.size())
            {
                if(prevBucket > -1)
                 {
                     maxGap = max(bucketMin[i] - bucketMax[prevBucket], maxGap);
                 }
                 prevBucket = i;
            }
            i++;
        }
        return maxGap;
    }
};
