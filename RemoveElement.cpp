/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int left = 0, right = 0;
        int length = n;
        while(right < n)
        {
            while(A[right] == elem && right < n)
            {
                length--;
                right++;
            }
            A[left] = A[right];
            left++;
            right++;
        }
        return length;
    }
};
