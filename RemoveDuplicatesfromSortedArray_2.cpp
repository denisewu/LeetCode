/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
       int left = 0, right = 1, repeat = 0;;
       if(n < 3)
            return n;
        while(right < n)
        {
            if(A[left] == A[right])
            {
                repeat++;
                if(repeat < 2)
                    A[++left] = A[right];
                
            }
            else
            {
                A[++left] = A[right];
                repeat = 0;
            }
            right++;
        }
        return left + 1;
    }
};
