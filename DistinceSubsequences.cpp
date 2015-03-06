/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/


class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.length() < T.length())
            return 0;
            
        vector<vector<int> > dp(S.length() + 1);
        for(int i = 0; i < S.length() + 1; i++)
        {
            dp[i] = vector<int>(T.length() + 1, 0);
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < S.length() + 1; i++)
            for(int j = 1; j < T.length() + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(S[i - 1] == T[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        return dp[S.length()][T.length()];
    }
};
