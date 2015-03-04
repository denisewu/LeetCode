/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        if(rowIndex < 0)
            return ret;
        for(int i = 0; i < rowIndex + 1; i++)
        {
            int temp = 0;
            for(int j = 0; j < ret.size(); j++)
            {
                 int temp2 = ret[j];
                 ret[j] = temp + ret[j];
                 temp = temp2;
            }
            ret.push_back(1);
         }
        return ret;
    }
};
