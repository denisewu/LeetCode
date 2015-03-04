/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.
*/
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            sum += pow(26, s.length() - 1 -i) * (s[i] - 'A' + 1);
        }
        return sum;
    }
};
