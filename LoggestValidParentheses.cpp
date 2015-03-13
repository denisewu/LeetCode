/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
       int left = 0;
       vector<int> dp(s.length() + 1, 0);
       int maxlen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
            {
                if(left > 0)
                {
                    left--;
                    dp[i + 1] = 2;
                    if(i > 0 && s[i - 1] == ')')
                        dp[i + 1] += dp[i];
                    dp[i + 1] += dp[i - dp[i + 1] + 1];
                    if(dp[i + 1] > maxlen)
                        maxlen = dp[i + 1];
                }
            }
                
        }
        return maxlen;
    }
