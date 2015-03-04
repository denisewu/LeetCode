//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if( i == 0)
                        firstRowZero = true;
                    if( j == 0)
                        firstColZero = true;
                }
            }
        for(int i = 1; i < matrix.size(); i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 1; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        if(!matrix.empty())
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(!matrix[0][j])
                {
                    for(int i = 1; i < matrix.size(); i++)
                        matrix[i][j] = 0;
                }
            }
        }
        if(firstRowZero && !matrix.empty())
        {
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        if(firstColZero)
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
        
        
        
    }
};
