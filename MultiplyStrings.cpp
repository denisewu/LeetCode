/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
   string add(string num1, string num2)
   {
        string ret;
        int carry = 0;
        int i, j;
        for(i = num1.length() - 1, j = num2.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            ret.append(1, char('0' + sum % 10));
            carry = sum / 10;
        }
        for(; i >= 0; i--)
        {
            int sum = num1[i] - '0' + carry;
            ret.append(1, char('0' + sum % 10));
            carry = sum / 10;
        }
        for(; j >= 0; j--)
        {
            int sum = num2[j] - '0' + carry;
            ret.append(1, char('0' + sum % 10));
            carry = sum / 10;
        }
        if(carry > 0)
            ret.append(1, char('0' + carry));
            
        reverse(ret);
        return ret;
    }
    
    void reverse(string& s)
    {
        for(int i = 0; i< s.length() / 2; i++)
        {
            char t = s[i];
            s[i] = s[s.length() - i - 1];
            s[s.length() - i - 1] = t;
        }
    }
public:
    string multiply2(string num1, string num2)
    {
            
    }
    
    string multiply(string num1, string num2) {
        string ret = "0";
        
        for(int i = num2.length() - 1; i >= 0; i--)
        {
            string s;
            int carry = 0;
            for(int j = num1.length() - 1; j >=0; j--)
            {
                int mul = (num2[i] - '0') * (num1[j] - '0') + carry;
                carry = mul / 10;
                s.append(1, char(mul % 10 + '0'));
            }
            if(carry > 0)
                s.append(1, char('0' + carry));
            reverse(s);
            
            for(int j = 0; j < (num2.length() - 1 - i); j++)
                s.append(1, '0');
            ret = add(ret, s);
        }
        int i = 0;
        for(; i < (ret.length() - 1); i++)
        {
            if(ret[i] != '0')
                break;
        }
        return ret.substr(i, ret.length() - i);
    }
};
