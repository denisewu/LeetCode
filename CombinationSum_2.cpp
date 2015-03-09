/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/
class Solution {
    void combinationSum2Aux(vector<int> &num, int start, int left, 
                                                vector<int>& currv, vector<vector<int> > &ret)
    {
        if(left == 0 && !currv.empty())
        {
            ret.push_back(currv);
            return;
        }
        if(left > 0)
        {
             for(int i = start; i < num.size(); i++)
             {
                 if(left < num[i]) return;
                 if(i && num[i] == num[i-1] && i > start) continue;
                 currv.push_back(num[i]);
                 combinationSum2Aux(num, i + 1, left - num[i], currv, ret);
                 currv.pop_back();
             }
        }
    }
    
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> v;
        vector<vector<int> > ret;
        combinationSum2Aux(num, 0, target, v, ret);
        return ret;
    }
};
