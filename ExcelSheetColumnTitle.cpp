/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    */
    class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n)
        {
            int t = n % 26;
            if (!t)
                t = 26;
            ret.push_back((char)('A' + t - 1));
            if(n % 26 == 0)
                n = n / 26 - 1;
            else
                n = n / 26;
        }
        for(size_t i = 0; i < ret.length() / 2; i++)
        {
            char temp = ret[i];
            ret[i] = ret[ret.length() - i - 1];
            ret[ret.length() - i - 1] = temp;
        }
        return ret;
    }
};
