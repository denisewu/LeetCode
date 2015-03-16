/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
class Solution {
    int expandAroundCenter(string& s, int c1, int c2)
    {
        int len = s.length();
        int l = c1, r = c2;
        while(l >= 0 && r < len && s[l] == s[r])
        {
            l--;
            r++;
        }
        return c1 == c2? c1 - l - 1: c1 - l;
    }
public:
    string longestPalindromeCenter(string s){
        int len = s.length();
        int retindex = 0;
        int longest = 1;
        for(int i = 0; i < len - 1; i++)
        {
            int radius = expandAroundCenter(s, i, i);
            if(radius * 2 + 1 > longest)
            {
                retindex = i - radius;
                longest = radius * 2 + 1;
            }
            radius = expandAroundCenter(s, i, i + 1);
            if(radius * 2 > longest)
            {
                retindex = i - radius + 1;
                longest = radius * 2;
            }
        }
        return s.substr(retindex, longest);
    }
    
    string longestPalindromeDP(string s) {
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
