/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1 || s.length() <= nRows)
            return s;
            
        string ret;
      
        for(int i = 0; i < (int)s.length() && i < nRows; i++)
        {
            int index = i;
            ret.append(1, s[i]);
            
            for(int j = 1; index < (int)s.length(); j++)
            {
                if(i == 0 || i == nRows - 1)
                {
                    index = index + nRows + nRows - 2;
                }
                else
                {
                    if(j % 2 == 1)
                        index += nRows * 2 - 2 - 2 * i;
                    else
                        index += 2 * i; 
                }
                if(index < (int)s.length())
                {
                    ret.append(1, s[index]);
                }
            }
        }
        return ret;
    }
};
