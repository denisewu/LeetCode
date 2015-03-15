/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
    int char2int(char c)
    {
        int ret = 0;
        switch(c)
        {
            case 'A':
                ret = 0;
                break;
            case 'C':
                ret = 1;
                break;
            case 'G':
                ret = 2;
                break;
            case 'T':
                ret = 3;
                break;
        }
        return ret;
    }
    int eraser = 0x3ffff ;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n = s.length();
        vector<string> ret;
        if(n < 10)
            return ret;
            
        bool wordset[1 << 20];
        bool resultset[1 << 20];
        memset(wordset, 0, sizeof(bool) * (1 << 20));
        memset(resultset, 0, sizeof(bool) * (1 << 20));
        unsigned num = 0;
        for(int j = 0; j < 10; j++)
        {
            num |= (char2int(s[j]));
            num <<= 2;
        }
        num >>= 2;
        int index = 0;
        for(int i = 10; i < n; i++)
        {
            if(wordset[num])
            {
                if(!resultset[num])
                {
                    ret.push_back(s.substr(index, 10));
                    resultset[num] = true;
                }
            }
            else
                wordset[num] = true;
            index++;
            num =(( num & eraser ) << 2) | char2int(s[i]);
        }
        if(wordset[num])
            {
                if(!resultset[num])
                {
                    ret.push_back(s.substr(index, 10));
                    resultset[num] = true;
                }
            }
            else
                wordset[num] = true;
        return ret;
    }
};
