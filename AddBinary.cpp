/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> s;
        string ret;
        int c = 0, i, j;
        for(i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            int sum = a[i] - '0' + b[j] - '0' + c;
            s.push((sum % 2) + '0');
            c = sum / 2;
        }
        for(; i >= 0; i--)
        {
            int sum = a[i] - '0' + c;
            s.push((sum % 2) + '0');
            c = sum / 2;
        }
        
        for(; j >= 0; j--)
        {
            int sum = b[j] - '0' + c;
            s.push((sum % 2) + '0');
            c = sum / 2;
        }
        
        if(c)
            s.push(c + '0');
            
        while(!s.empty())
        {
            ret.append(1, s.top());
            s.pop();
        }
        return ret;
    }
};
