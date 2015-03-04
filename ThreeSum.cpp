/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
      
        vector<vector<int> > ret;
        int n = num.size();
        for(int i = 0; i < n - 2; i++)
        {
            if(i > 0 && num[i] == num[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right)
            {
                if(left > i + 1 && num[left] == num[left - 1])
                {
                    left++;
                    continue;
                }
                if(right < n - 1 && num[right] == num[right + 1])
                {
                    right--;
                    continue;
                }
                int sum = num[left] + num[right] + num[i];
                if(sum == 0)
                {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[left]);
                    v.push_back(num[right]);
                    ret.push_back(v);
                    left++;
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return ret;
    }
};
