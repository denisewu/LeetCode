/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        vector<vector<int> > ret;
        for(int i = 0; i < (int)num.size() - 3; i++)
        {
            int target3 = target - num[i];
            for(int j = i + 1; j < (int)num.size() - 2; j++)
            {
                int target2 = target - num[i] - num[j];
                int left = j + 1;
                int right = (int)num.size() - 1;
                while(left < right)
                {
                    int sum = num[left] + num[right];
                    if(sum < target2)
                        left++;
                    else if(sum > target2)
                        right--;
                    else
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[left]);
                        v.push_back(num[right]);
                        ret.push_back(v);
                        while(left < right && num[left] == v[2])
                            left++;
                        while(left < right && num[right] == v[3])
                            right--;
                    }
                }
                
                while( (j < (int)num.size() - 3) && num[j + 1] == num[j])
                    j++;
            }
            while((i < (int)num.size() - 4) && num[i + 1] == num[i]) i++;
        }
        return ret;
        
    }
};
