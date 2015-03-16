/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2)
            return s;
        int len = s.length();
        bool isPal[1000][1000] = {false};
        int retindex = 0;
        int longest = 1;
        for(int i = 1; i < len; i++)
        {
            for(int j = 0; j < i + 1; j++)
            {
                if(s[j] == s[i] && (i - j < 2 || isPal[j + 1][i - 1]))
                {
                    isPal[j][i] = true;
                    if(i - j + 1 > longest)
                    {
                        longest = i - j + 1;
                        retindex = j;
                    }
                }
            }
        }
        return s.substr(retindex, longest);
    }
        
};
