/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> table;
        vector<string> ret;
        
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            map<string, vector<string> > ::iterator it = table.find(key);
            if(it == table.end())
            {
                table.insert(pair<string, vector<string> >(key, vector<string>()));
              
            }
            table[key].push_back(strs[i]);
        }
        map<string, vector<string> > :: iterator it = table.begin();
        for(; it != table.end(); it++)
        {
            if(it->second.size() > 1)
            {
                ret.insert(ret.end(), it->second.begin(), it->second.end());
            }
        }
        return ret;
        
    }
};
