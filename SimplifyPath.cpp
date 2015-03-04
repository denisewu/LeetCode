/*
* Given an absolute path for a file (Unix-style), simplify it.

* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
*/
class Solution {
public:
    string simplifyPath(string path) {
        string ret = "/";
        vector<string> v;
        int left = 0, right = 1;
        while(right < path.length())
        {
            while(right < path.length() && path[right] != '/')
                right++;
                
            if(path[right - 1] != '/')
            {
                string sub =path.substr(left + 1, right - left - 1);
                if(sub == ".." )
                {
                    if(!v.empty())
                        v.pop_back();
                }
                else if(sub != ".")
                    v.push_back(sub);
            }
            
            left = right;
            right++;
        }
        
        for(int i = 0; i < (int)v.size() - 1; i++)
        {
            ret += v[i];
            ret += "/";
        }
        if(v.size() > 0)
            ret += v[v.size() - 1];
        return ret;
    }
};
