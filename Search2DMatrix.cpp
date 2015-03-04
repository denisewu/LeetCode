/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
            return false;
        int up = 0, down = matrix.size() - 1;
        int mid;
        while(up <= down)
        {
            mid = (up + down) / 2;
            if(matrix[mid][0] == target )
                break;
            if(matrix[mid][0] < target)
            {
                if(mid == matrix.size() - 1)
                    break;
                else if(matrix[mid + 1][0] > target)
                    break;
                else
                    up = mid + 1;
            }
            else 
            {
                if(mid == 0)
                    break;
                else 
                    down = mid - 1;
            }
        }
        if(matrix[mid][0] == target)
            return true;
        else if(matrix[mid][0] > target)
            return false;
        
        int left = 0, right = matrix[mid].size();
        while(left <= right)
        {
            int mid2 = (left + right) / 2;
            if(matrix[mid][mid2] == target)
                return true;
            if(matrix[mid][mid2] < target)
                left = mid2 + 1;
            else
                right = mid2 - 1;
        }
        return false;
    }
};
