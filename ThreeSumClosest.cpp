
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
    
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int minGap = num[0] + num[1] + num[2] - target;
        for(int i = 0; i <(int)num.size() - 2; i++)
        {
            int left = i + 1;
            int right = (int)num.size() - 1;
            while(left < right)
            {
                int gap = num[i] + num[left] + num[right] - target;
                if(abs(gap) < abs(minGap))
                    minGap = gap;
                if(gap > 0)
                    right--;
                else if(gap == 0)
                    return target;
                else
                    left++;
            }
        }
        return target + minGap;
    }
};
