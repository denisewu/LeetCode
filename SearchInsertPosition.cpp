/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0 , right = n - 1;
        int mid = -1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target)
            {
                if(mid == 0 || A[mid - 1] < target )
                    return mid;
                else
                    right = mid - 1;
            }
            else
            {
                if(mid == n - 1 || A[mid + 1] > target)
                    return mid + 1;
                else
                    left = mid + 1;
            }
        }
        return 0;
    }
};
