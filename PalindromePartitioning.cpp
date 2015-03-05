/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
  */
  class Solution {
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void partitionAux(string &s, int pos, int len, vector<vector<string> > &ret, vector<string> &list, vector<vector<bool> > &m)
    {
            if(len == 0)
            {
                ret.push_back(list);
                return;
            }
           
            for(int i = 1; i <= len; i++)
            {
                string sub = s.substr(pos, i);
                if(m[pos][pos + i - 1])
                {
                    list.push_back(sub);
                    partitionAux(s, pos + i, len - i, ret, list, m);
                    list.pop_back();
                }
            }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        vector<string> list;
        if(s.empty())
            return ret;
        int len = s.length();
        vector<vector<bool> > m(len);
        for(int i = 0; i < len; i++)
        {
            vector<bool> row(len, 0);
            row[i] = true;
            m[i] = row;
        }
        for(int i = 0; i < len - 1; i++)
        {
            int left = 0;
            int right = i + 1;
            
            for(int j = len - i - 1; j > 0; j--)
            {
                if(s[left] == s[right])
                {
                    if(right - left > 1)
                    {
                        m[left][right] = m[left + 1][right - 1];
                    }
                    else
                        m[left][right] = true;
                }
                else
                    m[left][right] = false;
                right++;
                left++;
            }
        }
        
        partitionAux(s, 0, len, ret, list, m);
        return ret;
    }
};
