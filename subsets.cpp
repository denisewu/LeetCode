/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        if(S.empty())
            return ret;
        sort(S.begin(), S.end());
        ret.push_back(vector<int>());
        for(int i = 0; i < S.size(); i++)
        {
            int len = ret.size();
            for(int j = 0; j < len; j++)
            {
                vector<int> v = ret[j];
                v.push_back(S[i]);
                ret.push_back(v);
            }
        }
        return ret;
    }
};
