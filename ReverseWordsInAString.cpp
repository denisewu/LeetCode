/*
Reverse Words in a String 
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/
class Solution {
    void reverseString(string& s, int left, int right)
    {
         for(int i = left; i < (right + left) / 2; i++)
        {
            char t = s[i];
            s[i] = s[right - i + left - 1];
            s[right - i + left - 1] = t;
        }
    }
    
    bool isSpace(char c)
    {
        if(c == ' ' || c == '\t' )
            return true;
        else
            return false;
    }
    
public:
    void reverseWords(string &s) {
        bool head = true;
        int left = 0;
        while(left < s.length())
        {
            int i = left;
            while(i < s.length() && isSpace(s[i]))
                i++;
            if(head)
            {
                s.erase(left, i - left);
                head = false;
                left = 0;
            }
            else if(i == s.length())
            {
                s.erase(left, i - left);
                left = s.length();
            }
            else if(i - left > 1)
            {
                s.erase(left, i - left - 1);
            }
            
            if(left < (int)s.length() - 1 && isSpace(s[left]))
                left++;
            int right = left;
            while(right < s.length() && s[right] != ' ')
                right++;
            
            reverseString(s, left, right);
            left = right;
        }
        reverseString(s, 0, s.length());
    }
};
