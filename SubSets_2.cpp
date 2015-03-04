/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        if(S.empty())
            return ret;
            
        ret.push_back(vector<int>());
        sort(S.begin(), S.end());
        
        int i = 0;
        while(i < S.size())
        {
            i++;
            int count = 1;
            while(i < S.size() && S[i] == S[i - 1])
            {
                count++;
                i++;
            }
        
            int val = S[i - 1];
            
            int len = ret.size();
            for(int i = 0; i < len; i++)
            {
                vector<int> v = ret[i];
                for(int j = 0; j < count; j++)
                {
                    v.push_back(val);
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }
};
