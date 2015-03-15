/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
public:
    int atoi(string str) {
        int num = 0;
        int i = 0;
        for(; i < str.length(); i++)
            if(str[i] != ' ')
                break;
        int start = i;
        for(i = str.length() - 1; i >= 0; i--)
            if(str[i] != ' ')
                break;
        int end = i;
        if(start > end)
            return num;
        
        str = str.substr(start, end - start + 1);
        bool isNeg = false;
        start = 0;
        if(!isDigit(str[0]))
        {
            if(str[0] == '-')
                isNeg = true;
            else if(str[0] != '+')
                return num;
            start++;
        }
        for(int i = start; i < str.length(); i++)
        {
            if(!isDigit(str[i]))
                break;
            unsigned int temp = (unsigned int)INT_MAX - str[i] + '0';
            if(isNeg && (num > (temp + 1) / 10)
                || !isNeg && (num > temp / 10))
                return isNeg? INT_MIN: INT_MAX;
            num = num * 10 + str[i] - '0';
        }
        return isNeg? 0 - num: num;
    }
};
