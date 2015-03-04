//Given numRows, generate the first numRows of Pascal's triangle.
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        int row  = 0;
        while (row < numRows)
        {
            if(row == 0)
            {
                vector<int> v;
                v.push_back(1);
                ret.push_back(v);
            }
            else
            {
                vector<int> v;
                size_t i;
                for(i = 0; i < ret[row - 1].size(); i++)
                {
                    if(i == 0)
                        v.push_back(ret[row - 1][i]);
                    else
                        v.push_back(ret[row - 1][i] + ret[row - 1][i - 1]);
                }
                v.push_back(ret[row - 1][i - 1]);
                ret.push_back(v);
            }
            
            row++;
        }
        
        return ret;
    }
};
