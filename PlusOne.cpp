/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int> ret;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            ret.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry > 0)
            ret.push_back(carry);
      
        for(int i = 0; i < ret.size() / 2; i++)
        {
            int t = ret[i];
            ret[i] = ret[ret.size() - i - 1];
            ret[ret.size() - i - 1] = t;
        }
        return ret;
    }
};
