/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            char top = '\0';
            if(!stk.empty())
                top = stk.top();
            switch(s[i])
            {
                case '(':
                    stk.push(s[i]);
                    break;
                case '[':
                    stk.push(s[i]);
                    break;
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if(stk.empty() || top != '(')
                        return false;
                    else
                        stk.pop();
                    break;
                case ']':
                    if(stk.empty() || top != '[')
                        return false;
                    else
                        stk.pop();
                    break;
                case '}':
                    if(stk.empty() || top != '{')
                        return false;
                    else
                        stk.pop();
                    break;
                default:
                    return false;
            }
        }
        
        if(!stk.empty())
            return false;
        return true;
    }
};
