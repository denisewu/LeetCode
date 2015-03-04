/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(A[j] & bit)
                    count++;
            }
            if(count % 3)
                ret = ret | (1 << i);
        }
        return ret;
    }
};
