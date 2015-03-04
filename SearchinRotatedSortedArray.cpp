/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n == 0)
            return false;
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(A[mid] == target)
                return true;
           if(A[mid] > A[right])
           {
               if(A[mid] > target && A[left] <= target)
                    right = mid - 1;
               else
                    left = mid + 1;
           }
           else if(A[mid] < A[right])
           {
               if(A[mid] < target && A[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
           }
           else
                right--;
        }
        
        if(A[0] == target)
            return true;
        else
            return false;
    }
};
