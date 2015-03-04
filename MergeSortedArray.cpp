/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int move = 0;
        while(i< m + move && j < n)
        {
            if(A[i] > B[j])
            {
                for(int k = m + move - 1; k > i - 1; k--)
                    A[k + 1] = A[k];
                A[i] = B[j];
                j++;
                move++;
            }
            i++;
        }
        for(int k = j; k < n; k++)
        {
            A[i + k - j] = B[k];
        }
    }
};
