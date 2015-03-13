/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty())
            return "";
            
       int require[128];
       bool exist[128];
       memset(exist, 0, 128 * sizeof(bool));
       memset(require, 0, 128 * sizeof(int));
       for(int i = 0; i < T.size(); i++)
       {
           require[T[i]]++;
           exist[T[i]] = true;
       }
       
       queue<int> indexq;
       int left = 0, right = -1;
       int count = T.size();
       int minLen = INT_MAX;
       int minIndex = -1;
       
       while(right < (int)S.size())
       {
            if(count == 0)
            {
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minIndex = left;
                }
                require[S[left]]++;
                if(exist[S[left]] && require[S[left]] > 0)
                    count++;
                left++;
            }
            else
            {
                right++;
                if(right >= (int)S.size())
                    break;
                require[S[right]]--;
                if(exist[S[right]] && require[S[right]] >= 0)
                {
                   count--;
                }
            }
            
       }
        if(minIndex < 0)
            return "";
        else
            return S.substr(minIndex, minLen);
    }
};
