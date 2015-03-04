/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
class Solution {
public:
    void sortColors(int A[], int n) {
       int low = 0, high = n - 1;
        for(int i = low; i <= high;)
        {
            if(A[i] == 0)
            {
                A[i++] = A[low];
                A[low] = 0;
                low++;
            }
            else if(A[i] == 2)
            {
                A[i] = A[high];
                A[high] = 2;
                high--;
            }
            else
                i++;
        }
        
    }
};
