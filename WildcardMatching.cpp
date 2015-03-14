/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = s, *pp = p;
        bool star = false;
        const char * pt = NULL;
        while(*ss != '\0')
        {
            switch(*pp)
            {
                case '?':
                    ss++;
                    pp++;
                    break;
                    
                case '*':
                    star = true;
                    s = ss;
                    p = pp;
                    do
                    {
                        p++;
                    }while(*p == '*');
                    if(*p == '\0')
                        return true;
                    ss = s;
                    pp = p;
                    break;
                    
                default:
                    if(*ss == *pp)
                    {
                        ss++;
                        pp++;
                    }
                    else
                    {
                        if(!star)
                            return false;
                        s++;
                        ss = s;
                        pp = p;
                           
                    }
                    break;
            }
        }
        while(*pp == '*')
            pp++;
        return *pp == '\0';
    }
};
