/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        
        int max = 0;
        bool exist[128] = {false};
        int left = 0, right = 0;
        while(right < s.length())
        {
            if(exist[s[right]] == false)
            {
                exist[s[right]] = true;
                right++;
            }
            else 
            {
                if(right - left > max)
                {
                    max = right - left;
                }
                 while(left < right)
                {
                    if(s[left] != s[right])
                    {
                        exist[s[left]] = false;
                        left++;
                    }
                    else
                    {
                        left++;
                        right++;
                        break;
                    }
                }
            }
                
        }
        if(right - left > max)
            max = right - left;
        return max;
    }
};
