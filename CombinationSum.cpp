/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
class Solution {
   void combinationSumAux(vector<int>& candidates, int start, vector<int> currv, int left, vector<vector<int> >& ret)
   {
       if(left == 0 && !currv.empty())
       {
           ret.push_back(currv);
           return;
       }
       if(left > 0)
       {
            for(int i = start; i < candidates.size(); i++)
            {
                int maxc = left / candidates[i];
                vector<int> t = currv;
                for(int j = 0; j < maxc; j++)
                {
                    t.push_back(candidates[i]);
                    int newLeft = left - (j + 1) * candidates[i];
                    if(newLeft < candidates[i])
                    {
                        if(newLeft == 0)
                            ret.push_back(t);
                        break;
                    }
                    combinationSumAux(candidates, i + 1, t, newLeft, ret);
                }
            }
       }
   }

    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currv;
        vector<vector<int> > ret;
        combinationSumAux(candidates, 0, currv, target, ret);
        return ret;
    }
};
