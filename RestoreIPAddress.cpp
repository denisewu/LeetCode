/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
    void restoreIpAddressesAux(string& s, int start, int count, string currs, vector<string>& ret)
    {
       if(count == 4)
       {
           if(start == s.length())
           {
               ret.push_back(currs);
           }
           return;
       }
       for(int i = 1; i < 4; i++)
       {
           string sub = s.substr(start, i);
           if((i > 2 && atoi(sub.c_str()) > 255) ||
                ((i > 1)&& s[start] == '0')||
                s.length() - start < i)
            return;
            string t = currs;
            if(!t.empty())
                t += "." + sub;
            else
                t = sub;
            restoreIpAddressesAux(s, start + i, count + 1, t, ret);
       }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        restoreIpAddressesAux(s, 0, 0, "", ret);
        return ret;
    }
};
