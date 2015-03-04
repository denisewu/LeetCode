/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
class Solution {
    void rotateShell(vector<vector<int> >& matrix, int left, int right)
    {
        int n = matrix.size();
        for(int i = 0; i < right - left; i++)
        {
            int temp = matrix[left][left + i];
            matrix[left][left + i] = matrix[n - left - 1 - i][left];
            matrix[n - left - 1 - i][left] = matrix[n - left - 1][right - i];
            matrix[n - left - 1][right - i] = matrix[left + i][right];
            matrix[left + i][right] = temp;
        }
    }
    
public:
    void rotate(vector<vector<int> > &matrix) {
        int left = 0, right = matrix.size() - 1;
        while(left < right)
        {
            rotateShell(matrix, left, right);
            left++;
            right--;
        }
    }
};
