//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int col = 0;
        bool found = false;
        if(strs.empty())
            return "";
        
        string ret;
        while(1)
        {
            char c;
            for(int i = 0; i < strs.size(); i++)
            {
                if(i)
                {
                    if(col > strs[i].length() - 1 || strs[i][col] != c)
                    {
                        found = true;
                        break;
                    }
                }
                else
                {
                    if(col > (int)strs[i].length() - 1)
                    {
                        found = true;
                        break;
                    }
                    c = strs[i][col];
                }
            }
            if(!found)
            {
                ret.append(1, c);
                col++;
            }
            else
                break;
        }
        return ret;
    }
};
