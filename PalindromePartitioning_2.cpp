/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    int minCut(string s) {
        if(s.empty())
            return 0;
        int len = s.length();
        vector<vector<bool> > isPal(len, vector<bool>(len, false));
        int dp[len];

        for(int i = 0; i < len; i++)
            dp[i] = i;
            
        for(int i = 1; i < len; i++)
        {
           for(int j = 0; j < i + 1; j++)
           {
               if(s[j] == s[i] &&((i - j) < 2 || isPal[j + 1][i - 1]))
               {
                   isPal[j][i] = true;
                   if(j > 0)
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    else
                        dp[i] = 0;
               }
           }
        }
        return dp[s.length() - 1];
    }
};
