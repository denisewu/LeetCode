/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
    void buildpath(unordered_map<string, vector<string> >& prevs,
                    string word, vector<string> &path,  vector<vector<string> > &paths)
    {
        if(prevs[word].empty())
        {
            path.push_back(word);
            vector<string> tpath = path;
            reverse(tpath.begin(), tpath.end());
            paths.push_back(tpath);
            path.pop_back();
            return;
        }
        vector<string> v = prevs[word];
        path.push_back(word);
        for(int i = 0; i < v.size(); i++)
        {
            buildpath(prevs, v[i], path, paths);
        }
        path.pop_back();
    }
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > paths;
        
        unordered_map<string, vector<string> > prevs;
        prevs[start] = vector<string>();
        
        unordered_map<string, int> dists;
        dists[start] = 1;
        
        queue<string> q;
        q.push(start);
        
        dict.insert(start);
        dict.insert(end);
      
        while(!q.empty())
        {
            string head = q.front();
            q.pop();
            int dist = dists[head];
            for(int i = 0; i < head.length(); i++)
            {
                for(int j = 0; j < 26; j++)
                {
                    if(j + 'a' == head[i])
                        continue;
                    string temp = head;
                    temp[i] = j + 'a';
                    if(dict.find(temp) == dict.end())
                        continue;
                        
                    if(dists.find(temp) == dists.end()) 
                    {
                        q.push(temp);
                        dists[temp] = dist + 1;
                    }
                    if(dists[temp] > dist)
                    {
                        if(prevs.find(temp) == prevs.end())
                            prevs[temp] = vector<string>();
                        prevs[temp].push_back(head);
                    }
                }
            }
        }
        if(prevs[end].empty())
            return paths;
        vector<string> path;
        buildpath(prevs, end, path, paths);
        return paths;
    }
};
