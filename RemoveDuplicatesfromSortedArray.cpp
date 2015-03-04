/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int left = 0, right = 1;
        int length = n;
        for(;left < n - 1, right < n; right++)
        {
            if(A[right] > A[left])
                A[++left] = A[right];
            else
                length --;
        }
        return length;
    }
};
