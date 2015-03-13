/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)
            return 1;
        
        queue<string> q;
        q.push(start);
        unordered_map<string, int> hashtable;
        hashtable[start] = 1;
        int dist = 1;
        
        while(!q.empty())
        {
            string head = q.front();
            int dist = hashtable[head];
            q.pop();
            for(int i = 0; i < head.length(); i++)
            {
                for(int j = 'a'; j <= 'z'; j++)
                {
                    if(head[i] == j)
                        continue;
                    string headt = head;
                    headt[i] = j;
                    if(headt == end)
                        return dist + 1;
                    if(dict.find(headt) != dict.end() && hashtable.find(headt) == hashtable.end())
                    {
                        hashtable[headt] = dist + 1;
                        q.push(headt);
                    }
                }
            }
        }
        return 0;
    }
};
