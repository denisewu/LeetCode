/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
    void permuteAux(vector<int>& num, int i, vector<vector<int> > &ret)
    {
        if(i == num.size())
        {
            ret.push_back(num);
            return;
        }
        
        for(int j = i; j < num.size(); j++)
        {
            if(j > i)
                swap(num[i], num[j]);
            permuteAux(num, i + 1, ret);
            if(j > i)
                swap(num[i], num[j]);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
         vector<vector<int> > ret;
         if(num.empty())
            return ret;
         for(int i = 0 ; i < num.size(); i++)
         {
            if(i == 0)
            {
                vector<int> v;
                v.push_back(num[i]);
                ret.push_back(v);
            }
            else
            {
                int len = ret.size();
                for(int j = 0 ; j < len; j++)
                {
                    vector<int> v = ret[j];
                    for(int k = 0; k < v.size() + 1; k++)
                    {
                        vector<int> t = v;
                        t.insert(t.begin() + k, num[i]);
                        ret.push_back(t);
                    }
                }
                ret.erase(ret.begin(), ret.begin() + len);
            }
         }
         return ret;
         /*
        vector<vector<int> > ret;
        permuteAux(num, 0, ret);
        return ret;
         */
         
    }
};
