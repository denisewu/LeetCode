/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() < 2)
            return;
            
        int i = -1, j;
        for(i = num.size() - 2; i >= 0; i--)
        {
            if(num[i] < num[i + 1])
                break;
        }
       if(i > -1)
       {
            for(j = num.size() - 1; j > i; j--)
            {
                if(num[j] > num[i])
                    break;
            }
       
            int t = num[i];
            num[i] = num[j];
            num[j] = t;
       }
       i++;
       for(int j = 0; j < (num.size() - i) / 2; j++)
       {
           int t = num[i + j];
           num[i + j] = num[num.size() - j - 1];
           num[num.size() - j - 1] = t;
       }
    }
};
