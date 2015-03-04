/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;
        int left = 0, right = s.length() - 1;
        while(left < right)
        {
            while(!isChar(s[left]) && !isDigit(s[left]) && left < right)
                left++;
            
            while(!isChar(s[right]) && !isDigit(s[right]) && left < right)
                right--;
            
            if(left < right)
            {
                if(isDigit(s[left]) ^ isDigit(s[right]))
                    return false;
                
                if(isDigit(s[left]) && isDigit(s[right]) && s[left] != s[right])
                    return false;
                    
                int minus = s[left] - s[right];
                if(!(minus == 0 || minus == 'A' - 'a' || minus == 'a' - 'A'))
                    return false;
                    
                left++;
                right--;
            }
        }
        
        return true;
    }
    
private:
    bool isChar(char c)
    {
        if((c >='a' && c <= 'z') || (c >='A' && c <= 'Z') )
            return true;
        else
            return false;
    }
    
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        else
            return false;
    }
};
