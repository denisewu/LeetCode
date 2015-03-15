/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
    
public:
    bool isNumber(string s) {
        bool front = true;
        int i = 0;
        for(; i < (int)s.length(); i++)
            if(s[i] != ' ')
                break;
        int start = i;
        i = (int)s.length() - 1;
        for(; i >= 0; i--)
            if(s[i] != ' ')
                break;
        int end = i;
        if(start > end)
            return false;
     
        s = s.substr(start, end - start + 1);
        i = 0;
        bool dot = false;
        bool sign = false;
        bool e = false;
        bool digit = false;
        while(i < s.length())
        {
            if(isDigit(s[i]))
            {
               digit = true;
               sign = true;
               
            }
            else if(s[i] == '.' && !dot)
            {
                dot = true;
                sign = true;
            }
            else if(digit && !e && (s[i] == 'e' || s[i] == 'E'))
            {
                dot = true;
                e = true;
                digit = false;
                sign = false;
            }
            else if(!digit && !sign && (s[i] == '+' || s[i] == '-'))
                sign = true;
            else
                return false;
            i++;
        }
       
        return digit;
    }
};
