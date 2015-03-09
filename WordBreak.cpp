/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length(), false);
        for(int i = 0; i < s.length(); i++)
        {
            string sub = s.substr(0, i + 1);
            if(dict.find(sub) == dict.end())
            {
                bool rltFori = false;
                for(int j = 0; j < i; j++)
                {
                    if(dp[j])
                    {
                        string sub2 = s.substr(j + 1, i - j);
                        if(dict.find(sub2) != dict.end())
                        {
                            rltFori = true;
                            break;
                        }
                    }
                }
                dp[i] = rltFori;
            }
            else
            {
                dp[i] = true;
            }
        }
        return dp[s.length() - 1];
    }
};
