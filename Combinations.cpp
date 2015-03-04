//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

class Solution {
    void combineAux(int n, int k, int start, vector<int> currv, vector<vector<int> >& ret)
    {
        if(currv.size() == k)
        {
            ret.push_back(currv);
            return;
        }
        for(int i = start; i <= n; i++)
        {
            vector<int> t = currv;
            t.push_back(i);
            combineAux(n, k, i + 1, t, ret);
        }
    }
    
    vector<vector<int> > combineIter(int n, int k)
    {
        vector<vector<int> > ret;
        vector<int> v = {1};
        bool changeFront = false;
        while(!v.empty() && v[0] <= n - k + 1)
        {
            if(v.size() == k)
            {
                ret.push_back(v);
            }
            int val = v[v.size() - 1];
            if(val < n)
            {
                if(v.size() == k || changeFront)
                {
                    v.pop_back();
                    changeFront = false;
                }
                v.push_back(val + 1);
            }
            else
            {
                v.pop_back();
                changeFront = true;
            }
        }
        return ret;
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
        /*
        vector<int> v;
        vector<vector<int> > ret;
        combineAux(n, k, 1, v, ret);
        return ret;*/
        return combineIter(n, k);
    }
};
