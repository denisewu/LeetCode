/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
    void wordBreakAux(string& s, unordered_set<string> &dict, int pos,
                string& sentence, vector<string> &ret)
    {
        if(pos == s.length())
        {
            ret.push_back(sentence);
            return;
        }
        
        for(int i = 1; i < s.length() - pos + 1; i++)
        {
            string sub = s.substr(pos, i);
            if(dict.find(sub) != dict.end())
            {
                int sublen = 0;
                if(!sentence.empty())
                {
                    sentence.append(1, ' ');
                    sublen += 1;
                }
                sentence += sub;
                sublen += sub.length();
                wordBreakAux(s, dict, pos + i, sentence, ret);
                sentence.erase(sentence.length() - sublen, sublen);
            }
        }
    }
     bool breakable(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length(), false);
        for(int i = 0; i < s.length(); i++)
        {
            string sub = s.substr(0, i + 1);
            if(dict.find(sub) == dict.end())
            {
                bool rltFori = false;
                for(int j = 0; j < i; j++)
                {
                    if(dp[j])
                    {
                        string sub2 = s.substr(j + 1, i - j);
                        if(dict.find(sub2) != dict.end())
                        {
                            rltFori = true;
                            break;
                        }
                    }
                }
                dp[i] = rltFori;
            }
            else
            {
                dp[i] = true;
            }
        }
        return dp[s.length() - 1];
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        if(!breakable(s, dict))
            return ret;
        string sentence;
        wordBreakAux(s, dict, 0, sentence, ret);
        return ret;
    }
};
