/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v = numbers;
        sort(v.begin(), v.end());
        int retLeft1, retRight1, retLeft2, retRight2;
        int left = 0;
        int right = v.size() - 1;
        while(left < right)
        {
            int sum = v[left] + v[right];
            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
            {
                retLeft1 = left;
                retRight1 = right;
                break;
            }
        }
        for(int i = 0; i < numbers.size(); i++)
        {
            if(v[retLeft1] == numbers[i])
            {
                retLeft2 = i;
                break;
            }
        } 
        
        for(int i = 0; i < numbers.size(); i++)
        {
            if(v[retRight1] == numbers[i] && i != retLeft2)
            {
                retRight2 = i;
                break;
            }
        }
        if(retLeft2 > retRight2)
        {
            int temp = retLeft2;
            retLeft2 = retRight2;
            retRight2 = temp;
        }
        
        vector<int> ret;
        ret.push_back(retLeft2 + 1);
        ret.push_back(retRight2 + 1);
        return ret;
    }
};
