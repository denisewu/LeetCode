/*

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.length();
        if(s1.compare(s2) == 0)
            return true;
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if(temp1.compare(temp2) != 0)
            return false;
            
        for(int len = 1; len < m; len++)
        {
            string strl1 = s1.substr(0, len);
            string strr1 = s1.substr(len, m - len);
            string strl2 = s2.substr(0, len);
            string strr2 = s2.substr(len, m - len);
            if(isScramble(strl1, strl2) && isScramble(strr1, strr2))
                return true;
            
            string strl22 = s2.substr(0, m - len);
            string strr22 = s2.substr(m - len, len);
            if(isScramble(strl1, strr22) && isScramble(strr1, strl22))
                return true;
        }
        return false;
        
    }
};
